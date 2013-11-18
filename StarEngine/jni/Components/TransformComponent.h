#pragma once

#include "..\defines.h"
#include "BaseComponent.h"

namespace star
{
	struct Context;
	class Object;

	class TransformComponent final: public star::BaseComponent
	{
	public:
		enum TransformChanged : byte
		{
			NONE = 0,
			TRANSLATION = 1,
			ROTATION = 2,
			SCALE = 4,
			ALL = 7
		};

		TransformComponent(Object* parent);
		~TransformComponent(void);

		void Update(const Context& context);
		void Draw();
		void IsChanged(bool isChanged);
#ifdef STAR2D
		void Translate(const vec2& translation);
		void Translate(float x, float y);
		void Translate(const vec2& translation, lay l);
		void Translate(float x, float y, lay l);
		void Translate(const pos & pos2D);
		void TranslateX(float x);
		void TranslateY(float y);
		void TranslateL(lay l);

		void Move(const vec2& translation);
		void Move(float x, float y);
		void MoveX(float x);
		void MoveY(float y);

		void Rotate(float rotation);
		void Rotate(float rotation, const pos& centerPoint);
		void RotateLocal(float rotation);
		void RotateLocal(float rotation, const pos& centerPoint);

		void Scale(const vec2& scale);
		void Scale(float x, float y);
		void Scale(float u);
		void ScaleX(float x);
		void ScaleY(float y);
				
		const pos& GetWorldPosition();
		const pos& GetLocalPosition();
		float GetWorldRotation();
		float GetLocalRotation() const;
		const vec2& GetWorldScale();
		const vec2& GetLocalScale();
#else
		void Translate(const vec3& translation);
		void Translate(float x, float y, float z);
		void TranslateXY(float x, float y);
		void TranslateXZ(float x, float z);
		void TranslateX(float x);
		void TranslateYZ(float y, float z);
		void TranslateY(float y);
		void TranslateZ(float z);

		void Move(const vec3& translation);
		void Move(float x, float y, float z);
		void MoveXY(float x, float y);
		void MoveXZ(float x, float z);
		void MoveX(float x);
		void MoveYZ(float y, float z);
		void MoveY(float y);
		void MoveZ(float z);

		void Rotate(const quat & rotation);

		void Scale(const vec3& scale);
		void Scale(float x, float y, float z);
		void Scale(float u);
		void ScaleXY(float x, float y);
		void ScaleXZ(float x, float z);
		void ScaleX(float x);
		void ScaleYZ(float y, float z);
		void ScaleY(float y);
		void ScaleZ(float z);

		const vec3& GetWorldPosition();
		const vec3& GetLocalPosition();
		const quat& GetWorldRotation();
		const quat& GetLocalRotation() const;
		const vec3& GetWorldScale();
		const vec3& GetLocalScale();
#endif
		const mat4x4 & GetWorldMatrix() const;

	private:
		void InitializeComponent();
		void CheckForUpdate(const bool force = false);
		void CommonUpdate();
		void SingleUpdate(mat4x4 & world);

		suchar m_IsChanged;
		bool m_Invalidate;
		bool m_bRotationCenterChanged, m_bRotationIsLocal;

#ifdef STAR2D
		pos m_WorldPosition, m_LocalPosition,m_CenterPosition;
		float m_WorldRotation, m_LocalRotation;
		vec2 m_WorldScale, m_LocalScale;
#else
		vec3 m_WorldPosition, m_LocalPosition;
		quat m_WorldRotation, m_LocalRotation;
		vec3 m_WorldScale, m_LocalScale;
#endif
		mat4x4 m_World;

		TransformComponent(const TransformComponent& yRef);
		TransformComponent(TransformComponent&& yRef);
		TransformComponent& operator=(const TransformComponent& yRef);
		TransformComponent& operator=(TransformComponent&& yRef);
	};
}
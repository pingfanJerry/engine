#include "BaseComponent.h"
#include "..\SceneGraph\Object.h"
#include "..\Context.h"
#include "..\Logger.h"

namespace star
{
	BaseComponent::BaseComponent():
		m_pParentObject(nullptr),
		m_bInitialized(false)
	{
	}

	BaseComponent::BaseComponent(Object* parent):
		m_pParentObject(parent),
		m_bInitialized(false)
	{
	}

	BaseComponent::~BaseComponent(void)
	{
	}

	void BaseComponent::Initialize()
	{
		if(m_bInitialized)
		{
			return;
		}

		InitializeComponent();
		m_bInitialized = true;
	}

	BaseScene* BaseComponent::GetGameScene() const
	{ 
		return m_pParentObject->GetScene();
	}
}
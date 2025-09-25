#include <memory>
#include <vector>
#include "state-machine.hpp"
#include "mock-event-receiver.hpp"
#include "state-type.hpp"
#include "event-type.hpp"
#include "event.hpp"
#include <gtest/gtest.h>

using std::shared_ptr;
using std::make_shared;
using std::vector;
using ::testing::Truly;
using event_loops::core::StateType;
using event_loops::core::EventType;
using event_loops::oop::StateMachine;
using event_loops::oop::IEventReceiver;
using event_loops::oop::MockEventReceiver;
using event_loops::oop::Event;

class StateMachineTest : public testing::Test
{
protected:
  StateMachineTest(void) :
    m_pMockEventReceiver(make_shared<MockEventReceiver>()),
    m_theStateTypes{
      StateType::Init,
      StateType::Idle,
      StateType::Running,
      StateType::Paused,
      StateType::Stopped,
      StateType::Error,
    },
    m_stateMachine(m_pMockEventReceiver)
  {
  }

  shared_ptr<MockEventReceiver> m_pMockEventReceiver;
  vector<StateType> m_theStateTypes;
  StateMachine m_stateMachine;
};

TEST_F(StateMachineTest, VerifyInitialStateIsNone)
{
  const StateType expectedType(StateType::None);
  const StateType actualType(m_stateMachine.getCurrentState());
  
  ASSERT_EQ(expectedType, actualType);
}

TEST_F(StateMachineTest, ChangeStateVerifyStateIsUpdated)
{
  for (auto stateType : m_theStateTypes)
  {
    m_stateMachine.changeState(stateType);
    
    const StateType actualType(m_stateMachine.getCurrentState());

    ASSERT_EQ(stateType, actualType);
  }
}

TEST_F(StateMachineTest, ChangeStateVerifyEventIsPublished)
{
  for (auto stateType : m_theStateTypes)
  {
    const Event expectedEvent(EventType::StateChanged, stateType);
    EXPECT_CALL(*m_pMockEventReceiver,
                publishEvent(Truly([&](const Event& ev){
                  return
                    ev.getEventType() == EventType::StateChanged &&
                    ev.getPayload().type() == typeid(StateType) &&
                    std::any_cast<StateType>(ev.getPayload()) == stateType;
                })));

    m_stateMachine.changeState(stateType);
  }
}

#include <iostream>
#include <memory>

class FanContext;
// --- State Interface ---
class State
{
public:
    virtual ~State() = default;

    virtual void pressButton(class FanContext *context) = 0;
    virtual std::string name() const = 0;
};

// --- Concrete States ---
class OffState : public State
{
public:
    void pressButton(FanContext *context) override;
    std::string name() const override { return "Off"; }
};

class LowState : public State
{
public:
    void pressButton(FanContext *context) override;
    std::string name() const override { return "Low"; }
};

class HighState : public State
{
public:
    void pressButton(FanContext *context) override;
    std::string name() const override { return "High"; }
};

class FanContext
{
private:
    std::unique_ptr<State> m_state;

public:
    FanContext(std::unique_ptr<State> initialState) : m_state(std::move(initialState)) {}

    void setState(std::unique_ptr<State> newState)
    {
        m_state = std::move(newState);
    }

    void pressButton()
    {
        m_state->pressButton(this);
    }

    void showState()
    {
        std::cout << "Fan is in " << m_state->name() << " state.\n";
    }
};

void OffState::pressButton(FanContext *context)
{
    std::cout << "Turning fan to Low speed.\n";
    context->setState(std::make_unique<LowState>());
}

void LowState::pressButton(FanContext *context)
{
    std::cout << "Turning fan to High speed.\n";
    context->setState(std::make_unique<HighState>());
}

void HighState::pressButton(FanContext *context)
{
    std::cout << "Turning fan Off.\n";
    context->setState(std::make_unique<OffState>());
}

int main()
{
    FanContext fan(std::make_unique<OffState>());
    fan.showState();

    fan.pressButton();
    fan.showState();

    fan.pressButton();
    fan.showState();

    fan.pressButton();
    fan.showState();
}

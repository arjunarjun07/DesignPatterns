#include "Creational\Builder.h"

MargharittaPizzaBuilder::MargharittaPizzaBuilder()
{
    m_pizza = new Pizza();
}

void MargharittaPizzaBuilder::buildPizzaSize()
{
    if (m_pizza)
        m_pizza->setSize(5);
}

void MargharittaPizzaBuilder::buildPizzaCrust()
{
    if (m_pizza)
        m_pizza->setCrustType("Thin");
}

void MargharittaPizzaBuilder::buildPizzaToppings()
{
    vector<string> toppings = { "onion", "tomato", "jalepenos"};
    m_pizza->setToppings(toppings);
}

Pizza* MargharittaPizzaBuilder::getPizzaObj()
{
    return m_pizza;
}

MargharittaPizzaBuilder::~MargharittaPizzaBuilder()
{
    cout<<" MargharittaPizzaBuilder destructor called"<<endl;

    if (m_pizza)
        delete m_pizza;
}

void MargharittaPizzaBuilder::reset()
{
    if (m_pizza)
    {
        m_pizza->setSize(0);
        m_pizza->setCrustType("");
        m_pizza->setToppings({});
    }
}

PizzaDirector::PizzaDirector()
{
    m_builder = nullptr;
}

void PizzaDirector::setPizzaBuilder(IPizzaBuilder* builder)
{
    m_builder = builder;
}

Pizza* PizzaDirector::constructPizza()
{
    if (m_builder)
    {
        m_builder->buildPizzaSize();
        m_builder->buildPizzaCrust();
        m_builder->buildPizzaToppings();
        
        return m_builder->getPizzaObj();
    }
    else
    {
        return nullptr;
    }
}

PizzaDirector::~PizzaDirector()
{
    cout<<" PizzaDirector destructor called"<<endl;
    //if (m_builder)
    //    delete m_builder;
}

/*
Uses:
    -  Use the Builder pattern to get rid of a “telescoping constructor”. (To avoid beasty constructors with many params)
    - Use the Builder pattern when you want your code to be able to create different representations of some product (for example, stone and wooden houses).
    - Use the Builder to construct Composite trees or other complex objects. You can even call steps recursively, which comes in handy when you need to build an object tree.
*/
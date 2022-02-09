cmake_minimum_required(VERSION 3.20)
project(Design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(Design_patterns
        "Behavioral Patterns/Command.cpp"
        "Behavioral Patterns/Interpreter.cpp"
        "Behavioral Patterns/Iterator.cpp"
        "Behavioral Patterns/Observer.cpp"
        "Behavioral Patterns/State.cpp"
        "Behavioral Patterns/Strategy.cpp"
        "Behavioral Patterns/Template.cpp"
        "Creational Patterns/Abstract Factory.cpp"
        "Creational Patterns/Builder.cpp"
        "Creational Patterns/Factory.cpp"
        "Creational Patterns/Prototype.cpp"
        "Creational Patterns/Singleton.cpp"
        "Structural Patterns/Adapter.cpp"
        "Structural Patterns/Bridge.cpp"
        "Structural Patterns/Decorator.cpp"
        "Structural Patterns/Facade.cpp"
        "Structural Patterns/Flyweight.cpp"
        "Structural Patterns/Proxy.cpp"
        "main .cpp")

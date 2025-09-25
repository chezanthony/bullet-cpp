bullet-cpp is a bare-bones event loop cpp library.
It creates the main event loop for your application and does the event propagation and handling.
It can be used for cli tooling, simple desktop application, or even a cpp based web application.
It does not have a strong preference over any UI library, it should work with most libraries.

It has two types of event loops:
- oop
- ecs

# OOP
The oop event loop does not refer to oop in the smalltalk sense, but in the cpp sense.
Meaning, the event loop infrastructure, the event publishers and subscribers are implemented using polymorphic classes.
Required member functions are enforced by interfaces by defining pure virtual functions.
Differences in behavior is done by creating different classes that implement the pure virtual functions differently.
Calling the correct class and instance of that class is done with the help of an enum.

This model is easy to follow as it is easy to map mentally.
This should work on most use cases and your run of the mill applications where the performance cost of using a vtable is of minimal importance.

# ECS
For use cases where either a lot of entities are being handled at any point in time, or if there is a strict requirement for handling events within a deadline, the ecs event loop should be best.
In this type, entities are stored in a contiguous memory block and differences in behavior is handled by a _system_ using a switch case.
Virtual inheritance is avoided as much as possible.
Entities are accessed by indexing on an array as opposed to jumping to an arbitrary memory in heap.

# Building From Source
To build the library from the source code, run the following from the project root directory:
```bash
cmake -S . -B build
cmake --build build
```

# Running Tests
To run the tests, make sure the project has been built (see instructions above).
Then, run the following from the project root directory:
```bash
ctest --test-dir build
```

# Project Info
> TODO: Move this to a more appropriate file.
**Project Creator & Maintainer**: Chez Anthony Intud (github.com/chezanthony)
Apart from the main purpose of creating a bare-bones pluggable cpp event-loop library, this project is created both to showcase the maintainer's current ability as well as expand on it.

## Phases
- project setup <-- active phase
- oop event loop (core)
- oop event loop (advanced features)
- oop event loop (optimization & extensions)
- ecs event loop (core)
- ecs event loop (advanced features)
- ecs event loop (optimization & extensions)
- polish and outreach

# AI Disclosure
AI is used for project management.
It creates the project phases, the stories, and their requirements.
Documentation is written by the maintainer without AI help (as evidenced by the lack of polish in structure and wording).
Small knowledge gaps are filled in by AI (Google searches has largely been replaced by ChatGPT, like how to do git X or git Y).
Cpp technical knowledge is a product of the maintainer's prior knowledge and experience supplemented by reading relevant source materials.

- What is the purpose of a forward declaration?
A forward declaration allows declaration of pointers to a certain class that is not yet defined.
It is good practice as it limits the likelihood of circular dependencies.

- What are the differences between the stack and the heap?
The stack has limited memory but management of it is easier as it gets freed automatically when leaving a context.
The heap opens access to memory on the RAM, but must be carefully managed to avoid memory leaks.

- What is the difference between a variable passsed by copy, by reference or by pointer?
When passed by copy, the entire variable will be copied and new memory will be allocated for it. It can be expensive.
By reference, the object passed will be the one to be used within the function. No copy is created.
By pointer, members of the object pointed to must be accessed with "->" as it is an indirect reference, but benefits are the same as by reference.

- What is a pure virual class?
A pure virtual class possesses functions that can be overriden, but these functions have no behaviour by default.

- What are the different phases of the compilation process?
The compiler starts by combining all classes to a single .o file that contains the whole code with all includes inlined.
It then reads this code top to bottom and translates instructions into machine code.
(Some languages or compilers may instead compile to assembly first, or compile to an intermediary language that can be interpreted)

- What is a smart-pointer? What problem do they solve? What problem do they bring?
A smart pointer makes use of pointers safer by removing the need to manually manage the memory they hold an address to.
However, their use is finicky: accessing the underlying object requires more boilerplate etc.

- What is the problem that multi-threading try to solve?
A program that runs on a single thread may hang or lag if one process takes too long.
Multi-threading allows the execution of long instructions in parallel without blocking the program.
Typically, a software that would freeze during a long instruction could instead display a nice loading bar and allow cancelation.

- Give at least two synchronization types that are used by multi-threading programs? What are their purpose?
Multi-threaded programs may use Update and Draw synchronizations. During Update, each thread is allocated a task, and during Draw, they may
manage the rendering.

- What is a Spin Lock?
A spin lock occurs when a thread waits for the next signal by looping indefinitely.

- What is a Dead Lock?
A dead lock occurs when a thread is stopped until the next signal recreates it.

- What does the following code display?
```cpp
int x = 10;
int* p = &x;
*p = 20;
std::cout << x << std::endl;
```
20

- What is the following code output?
```cpp
int* p = nullptr;
*p = 5;
std::cout << p << std::endl;
```
Error

- What does the following code display?
```cpp
class A {
public:
    virtual void f() { std::cout << "A"; }
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A* obj = new B();
obj->f();
``` 
B

- Does that code works?
```cpp
class A {
public:
    virtual void f() = 0
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A a;
a->f();

A* b = new B;
b->f();
``` 
No, a->f() is not implemented.

- What is the number of loop that program will execute?
``` cpp
unsigned char nbHalfLoop = 200;
for (unsigned char id = 0; id < 2 * nbHalfLoop; id++)
{
cout << id;
}
```
It will run infinitely, as computing 2 * nbHalfLoop will make it an int that equals to 400.
However, "id" remains an unsigned char, so when reaching 255, it will overflow back to 0 and never be higher than 400.

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

for (int i = 0; i < 100000; i++) {
    data.Add(i);
}

bool exists(int value) {
    for (int x : data) {
        if (x == value) return true;
    }
    return false;
}
```
A container fit for frequently adding values to it is std::list

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data = { 1, 2, 3, 4, 5 };

// ...

data.Insert(data.begin(), 0);
```
A container fit for adding values at its beginning is std::queue


- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

void add(int x) {
    for (int v : data) {
        if (v == x) return;
    }
    data.Add(x);
}
```
A container fit for being frequently accessed is std::vector
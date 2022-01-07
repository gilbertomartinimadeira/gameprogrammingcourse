#include <iostream>
#include <memory>


template <class T> class FlexArray
{
    size_t m_occupiedSpaces = 0;
    size_t m_size;
    T * m_array;

public:

    FlexArray()
    {

    }

    FlexArray(size_t size): m_size(size), m_array(new T[m_size])
    {
        std::cout << "Constructor" <<"\n";
    }

    ~FlexArray()
    {
        std::cout << "Destructor" << "\n";
        delete [] m_array;
    }

    void AddItem(T val)
    {
        if(m_occupiedSpaces < m_size)
        {
            m_array[m_occupiedSpaces] = val;
            ++m_occupiedSpaces;
        }else
        {
            std::cout << "Array is full !!!" << "\n";
        }
    }

    void setItem(size_t index, T value)
    {
        if(m_array[index] == 0) ++m_occupiedSpaces;
        if(index >= m_size){
            std::cout << "invalid assignment at index " << index << "\n";
            return;
        }
        m_array[index] = value;
    }

    void showValues()
    {
        std::cout << "Occupied Spaces: " << m_occupiedSpaces << "\n";
        for(size_t i = 0; i < m_size ; i++ )
        {
            std::cout << i << ": "  << m_array[i] <<"\n";
        }
    }

    T & operator [](size_t index)
    {
        return m_array[index];
    }


};
    template <class T> void ShowReferenceCount(std::shared_ptr<FlexArray<T>> sharedPointer)
    {
        std::cout << "References to sharedPointer: "<< sharedPointer.use_count() << "\n";
    }

int main()
{
    ///////////////////////////////////////////// DEMO 1
    // int i  = 1;

    // int *p = &i;

    // std:: cout <<" address of i: " << &i << "\n";
    // std:: cout <<" value of *p: " << p << "\n";

    // std::cout << "value stored at i using i: " << i <<"\n";
    // std::cout << "value stored at i using dereference in *p: " << *p <<"\n";

    


    ///////////////////////////////////////////// DEMO 2
    // int a = 10;
    // int b = 20;

    // std::cout << "valor de a: " << a << "\n";
    // std::cout << "valor de b: " << b << "\n";

    // int * pa = &a;
    // int * pb = &b;

    // std::cout << "endereço de a: " << pa << "\n";
    // std::cout << "endereço de b: " << pb << "\n";

    // *(&a+1) = 42;

    // std::cout << "valor de a: " << a << "\n";
    // std::cout << "valor de b: " << b << "\n";

    // return 0;

///////////////////////////////////////////// DEMO 3

    FlexArray<int> myIntArray(10);

    myIntArray.AddItem(1);
    myIntArray.AddItem(2);
    
    myIntArray.setItem(3,54);
    myIntArray.setItem(8,95);

    myIntArray.setItem(13,95);
    myIntArray.setItem(10,79);

    myIntArray[7] = 349;

 
    myIntArray.showValues();


    auto sharedArray = std::make_shared<FlexArray<int>>();

    ShowReferenceCount(sharedArray);

    
}
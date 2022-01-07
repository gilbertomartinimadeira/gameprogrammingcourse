#include <iostream>
#include <memory>
class IntArray
{
    size_t m_occupiedSpaces = 0;
    size_t m_size;
    int * m_array;

public:

    IntArray()
    {

    }

    IntArray(size_t size): m_size(size), m_array(new int[m_size])
    {
        std::cout << "Constructor" <<"\n";
    }

    ~IntArray()
    {
        std::cout << "Destructor" << "\n";
        delete [] m_array;
    }

    void AddItem(int val)
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

    void setItem(size_t index, int value)
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

    int & operator [](size_t index)
    {
        return m_array[index];
    }


};
    void ShowReferenceCount(std::shared_ptr<IntArray> sharedPointer)
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

    IntArray myIntArray(10);

    myIntArray.AddItem(1);
    myIntArray.AddItem(2);
    
    myIntArray.setItem(3,54);
    myIntArray.setItem(8,95);

    myIntArray.setItem(13,95);
    myIntArray.setItem(10,79);

    myIntArray[7] = 349;

 
    myIntArray.showValues();


    auto sharedArray = std::make_shared<IntArray>();

    ShowReferenceCount(sharedArray);

    
}
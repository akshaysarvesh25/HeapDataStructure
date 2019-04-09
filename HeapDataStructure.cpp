#include<stdlib.h>
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;


template <class T>
class Heap{

  private:
    std::vector<T> H;
    T *tail;

    std::vector<T> Swap(std::vector<T> H_,int x,int y)
    {
      T temp = H_[x];
      H_[x] = H_[y];
      H_[y] = temp;
      return H_;
    }

    bool MakeHeap_Parent(std::vector<T> H_,int n)
    {
      //cout<<"Index : "<<" : "<<(n-1)/2<<endl;
      unsigned int Parent_idx = (double)(n-1)/2;
      cout<<"Parent_idx : "<<Parent_idx<<endl;
      if(H_[n]>=H_[Parent_idx])
      {
        return true;
      }

      else
      {
        std::vector<T> H1 = Swap(H_,n,Parent_idx);
        H = H1;
        return MakeHeap_Parent(H1,Parent_idx);
      }

    }

  public:
    bool Insert(T value)
    {
      if(H.size() == 0)
      {
        H.push_back(value);
        //cout<<"Adding root"<<endl;
        return true;
      }

      else
      {
        //cout<<"size : "<<H.size()<<endl;
        H.push_back(value);
        //cout<<"Adding element to heap"<<endl;
        cout<<"H.size() : "<<H.size()-1<<endl;
        return MakeHeap_Parent(H,(H.size()-1));

      }
    }

    void print()
    {
      for(unsigned int i = 0;i<H.size();i++)
      {
        std::cout<<H[i]<<std::endl;
      }
    }



};

int main()
{
  Heap<int> *Heap1 = new Heap<int>();
  bool b = Heap1->Insert(10);
  b = Heap1->Insert(11);
  b = Heap1->Insert(12);
  b = Heap1->Insert(13);
  b = Heap1->Insert(9);
  b = Heap1->Insert(1);

  Heap1->print();
  return 0;
}

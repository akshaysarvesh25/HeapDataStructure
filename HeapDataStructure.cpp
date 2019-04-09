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

    T Min()
    {
      return H[0];
    }

    bool MakeHeap_Child(std::vector<T> H11,int i)
    {
      if((2*i)+1>(H11.size()-1))
      {
        return true;
      }

      if(H11[((2*i)+1)]<=H11[((2*i)+2)])
      {
        if(H11[i]<=H11[((2*i)+2)])
        {
          return true;
        }
        else
        {
          H = Swap(H11,i,((2*i)+1));
          return MakeHeap_Child(H,((2*i)+1));
        }
      }
      else
      {
        if(H11[i]<=H11[((2*i)+2)])
        {
          return true;
        }

        else
        {
          H = Swap(H11,i,((2*i)+2));
          return MakeHeap_Child(H,((2*i)+2));
        }
      }
    }

    bool Delete(T index)
    {
      if(H.size() == 0)
      {
        return false;
      }

      else
      {
        H[index] = H[H.size()-1];
        H.erase(H.end()-1);
        unsigned int P_idx = (double)(index-1)/2;

        if(H[index]<=H[P_idx])
        {
          return MakeHeap_Parent(H,index);
        }
        else if((H[index]>=H[(2*index)+1])||(H[index]>=H[(2*index)+2]))
        {
          return MakeHeap_Child(H,index);
        }
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
  b = Heap1->Insert(1);
  b = Heap1->Insert(1);
  b = Heap1->Insert(-11);
  b = Heap1->Insert(-12);

  Heap1->print();
  Heap1->Delete(2);
  Heap1->Delete(3);
  Heap1->Delete(4);
  cout<<"Deleting indices : 2,3,4"<<endl;
  cout<<"New Heap: "<<endl;
  Heap1->print();
  cout<<"Minimum element is : "<<Heap1->Min()<<endl;
  return 0;
}

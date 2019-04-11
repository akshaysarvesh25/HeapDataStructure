#include<stdlib.h>
#include <iostream>
#include<vector>
#include <cmath>

using namespace std;


template <class T>
class Heap{

  private:
    std::vector<T> H;
    std::vector<T> EdgeWeight;
    T *tail;

    std::vector<T> Swap(std::vector<T> H_,int x,int y)
    {
      T temp = H_[x];
      H_[x] = H_[y];
      H_[y] = temp;


      return H_;
    }

    bool MakeHeap_Parent(std::vector<T> weight_MP, std::vector<T> H_,int n)
    {
      //cout<<"Index : "<<" : "<<(n-1)/2<<endl;
      unsigned int Parent_idx = (double)(n-1)/2;
      //cout<<"Parent_idx : "<<Parent_idx<<endl;
      if(weight_MP[n]>=weight_MP[Parent_idx])
      {
        return true;

      }

      else
      {
        std::vector<T> H1 = Swap(H_,n,Parent_idx);
        H = H1;
        int TempPos = position[H_[n]];
        position[H_[n]] = position[H_[Parent_idx]];
        position[H_[Parent_idx]] = TempPos;
        std::vector<T> weight_MP_1 = Swap(weight_MP,n,Parent_idx);
        EdgeWeight = weight_MP_1;
        return MakeHeap_Parent(weight_MP_1,H1,Parent_idx);
      }

    }

    bool MakeHeap_Child(std::vector<T> weight11,std::vector<T> H11,int i)
    {
      if((2*i)+1>(H11.size()-1))
      {
        return true;
      }

      if(weight11[((2*i)+1)]<=weight11[((2*i)+2)])
      {
        if(weight11[i]<=weight11[((2*i)+2)])
        {
          return true;
        }
        else
        {
          H = Swap(H11,i,((2*i)+1));
          int TempPos = position[H[i]];
          position[H[i]] = position[H[(2*i)+1]];
          position[H[(2*i)+1]] = TempPos;
          EdgeWeight = Swap(weight11,i,((2*i)+1));
          return MakeHeap_Child(EdgeWeight,H,((2*i)+1));
        }
      }
      else
      {
        if(weight11[i]<=weight11[((2*i)+2)])
        {
          return true;
        }

        else
        {
          H = Swap(H11,i,((2*i)+2));
          int TempPos = position[H[i]];
          position[H[i]] = position[H[(2*i)+1]];
          position[H[(2*i)+1]] = TempPos;
          EdgeWeight = Swap(weight11,i,((2*i)+2));
          return MakeHeap_Child(EdgeWeight,H,((2*i)+2));
        }
      }
    }

  public:
    /* Position of the element in the heap */
    int position[5000];

    bool Insert(T value,T weight)
    {
      if(H.size() == 0)
      {
        H.push_back(value);
        EdgeWeight.push_back(weight);
        position[value] = H.size()-1;
        //cout<<"Added an element, H.size() is : "<<H.size()<<endl;
        return true;
      }

      else
      {
        //cout<<"size : "<<H.size()<<endl;
        H.push_back(value);
        EdgeWeight.push_back(weight);

        position[value] = H.size()-1;
        //cout<<"Adding element to heap"<<endl;
        //cout<<"H.size() : "<<H.size()<<endl;
        return MakeHeap_Parent(EdgeWeight,H,(H.size()-1));

      }
    }

    void print()
    {
      for(unsigned int i = 0;i<H.size();i++)
      {
        std::cout<<H[i]<<" "<<EdgeWeight[i]<<std::endl;
      }
    }

    T Min()
    {
      return H[0];
    }


    bool Delete(T index)
    {
      if(H.size() == 0)
      {
        cout<<"Nothing to delete"<<endl;
        return false;
      }

      else
      {
        int TempPos1 = position[H[index]];
        position[H[index]] = -1;
        H[index] = H[H.size()-1];
        position[H[H.size()-1]] = TempPos1;
        EdgeWeight[index] = EdgeWeight[EdgeWeight.size()-1];
        H.erase(H.end()-1);
        EdgeWeight.erase(EdgeWeight.end()-1);
        unsigned int P_idx = (double)(index-1)/2;

        if(EdgeWeight[index]<=EdgeWeight[P_idx])
        {
          return MakeHeap_Parent(EdgeWeight,H,index);
        }
        else if((EdgeWeight[index]>=EdgeWeight[(2*index)+1])||(EdgeWeight[index]>=EdgeWeight[(2*index)+2]))
        {
          return MakeHeap_Child(EdgeWeight,H,index);
        }
      }

    }



};

int main()
{
  Heap<int> *Heap1 = new Heap<int>();
  bool b = Heap1->Insert(7,1);
  b = Heap1->Insert(3,3);
  b = Heap1->Insert(1,2);
  b = Heap1->Insert(5,1);
  b = Heap1->Insert(4,2);
  b = Heap1->Insert(2,2);
  b = Heap1->Insert(0,20);
  b = Heap1->Insert(6,19);
  b = Heap1->Insert(10,2);
  b = Heap1->Insert(8,2);
  b = Heap1->Insert(11,2);
  b = Heap1->Insert(9,2);
  b = Heap1->Insert(12,2);
  Heap1->print();
  cout<<"Deleting..2\n";
  Heap1->Delete(2);
  Heap1->print();
  cout<<"Inserting..2 and 13\n";
  b = Heap1->Insert(1,2);
  b = Heap1->Insert(13,1);
  Heap1->print();
  
  for(int i = 0;i<14;i++)
  {
    cout<<"Position of "<<i<<" : "<<Heap1->position[i]<<endl;
  }
  /*
  Heap1->print();
  cout<<"Adding..\n";
  b = Heap1->Insert(9,2);
  Heap1->print();
  */

  /*


  b = Heap1->Insert(9,3);
  b = Heap1->Insert(1,5);
  b = Heap1->Insert(1,6);
  b = Heap1->Insert(1,7);
  b = Heap1->Insert(-11,8);
  b = Heap1->Insert(-12,9);

  Heap1->print();
  /*

  Heap1->Delete(3);
  Heap1->Delete(4);
  cout<<"Deleting indices : 2,3,4"<<endl;
  cout<<"New Heap: "<<endl;
  Heap1->print();
  cout<<"Minimum element is : "<<Heap1->Min()<<endl;
  */
  return 0;
}

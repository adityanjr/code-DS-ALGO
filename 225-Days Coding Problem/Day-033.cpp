/*
  
  
   This problem was asked by Microsoft.

   Compute the running median of a sequence of numbers.
   That is, given a stream of numbers, print out the median of the list so far on each new element.

   Recall that the median of an even-numbered list is the average of the two middle numbers.

   For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

   2
   1.5
   2
   3.5
   2
   2
   2
 *
 */
#include <bits/stdc++.h>
using namespace std;

/*
 *
 *  we are using two heaps to solve this question , you can use priority_queue in c++ for implementation of 
 *  min_heap & max_heap , or you can also create your heap data-structure 
 *
 *
 *
 *
 */




struct Heap{
    protected:
        vector< int > heap_array;

        Heap(){
            heap_array.clear();
        }

         
        int LeftChild(int current_node){
            return 2*current_node+1;
        }

        int RightChild(int current_node){
            return 2*current_node+2;
        }

        int Parent(int current_node){
            return (current_node-1)/2; 
        }

        virtual void Heapify(int current_node) = 0;

    public:

        int GetTop(void){
            return heap_array.at(0);
        }

        int HeapSize(void){
            return heap_array.size();
        }

        virtual int ExtractTop(void) = 0;
        virtual void InsertKey(int key) = 0;

        void print(void){
            for(auto&itr:heap_array){
                cout << itr << '\t';
            }
            cout<<'\n';
        }
};

struct MinHeap:public Heap{
    protected:
        void Heapify(int current_node){
            int left = LeftChild(current_node);
            int right = RightChild(current_node);
            int least_value_at = current_node; // to check where the least value exist 
            if(left <(int) heap_array.size() && heap_array[left] < heap_array[least_value_at]){
                least_value_at = left;
            }
            if(right <(int) heap_array.size() && heap_array[right] < heap_array[least_value_at]){
                least_value_at = right;
            }
            if(least_value_at != current_node){ // if the least value is already at top then we do nothing 
                swap(heap_array[current_node] , heap_array[least_value_at] );
                Heapify(least_value_at);
            }
        }
    public:

        int ExtractTop(void){
            int root_node_value = heap_array.at(0);
            heap_array.at(0) = heap_array.at(heap_array.size()-1);
            Heapify(0);
            heap_array.resize(heap_array.size()-1);
            return root_node_value;
        }

        void InsertKey(int value){
            if(heap_array.size()==0){
                heap_array.clear();
            }
            heap_array.push_back(value);
            int inserted_value_at = heap_array.size() - 1;
            while(inserted_value_at >= 1 && heap_array[Parent(inserted_value_at)] > heap_array[inserted_value_at]){
                swap(heap_array[Parent(inserted_value_at)] , heap_array[inserted_value_at]);
                inserted_value_at = Parent(inserted_value_at);
            }
        }
};
struct MaxHeap:public Heap{
    protected:
        void Heapify(int current_node){
            int left = LeftChild(current_node);
            int right = RightChild(current_node);
            int largest_value_at = current_node;
            
            if(left <(int) heap_array.size() && heap_array[left] > heap_array[largest_value_at]){
                largest_value_at = left;
            }

            if(right <(int) heap_array.size() && heap_array[right] > heap_array[largest_value_at]){
                largest_value_at = right;
            }

            if(largest_value_at != current_node){
                swap(heap_array[largest_value_at] , heap_array[current_node]);
                Heapify(largest_value_at);
            }
        }
    public:
        int ExtractTop(void){
            int root_node_value = heap_array.at(0);
            heap_array.at(0) = heap_array.at(heap_array.size() - 1);
            heap_array.resize(heap_array.size() - 1);
            Heapify(0);
            return root_node_value;
        }
        void InsertKey(int value){
            if(heap_array.size() == 0){
                heap_array.clear();
            }
            heap_array.push_back(value);
            int current_node = heap_array.size() - 1;
            while(current_node >= 1 && heap_array[Parent( current_node )] < heap_array[current_node]){
                swap(heap_array[Parent(current_node)] , heap_array[current_node]);
                current_node = Parent(current_node);
            }
        }
};





int main(void){
    int element; // take one element each time 
    MinHeap min_heap;
    MaxHeap max_heap;
    while(cin >> element){
        double mid;
        if(min_heap.HeapSize() == 0){
            min_heap.InsertKey(element);
            mid = min_heap.GetTop();
        }else if(max_heap.HeapSize() == 0){
            max_heap.InsertKey(element);
            mid = (max_heap.GetTop() + min_heap.GetTop())/2.0f;
        }else{
            if(element < max_heap.GetTop()){
                max_heap.InsertKey(element);
            }else{
                min_heap.InsertKey(element);
            }

            // rebalancing the size of heaps 

            if(max_heap.HeapSize() - min_heap.HeapSize() >=2){
                min_heap.InsertKey(max_heap.ExtractTop());
            }else if(min_heap.HeapSize() - max_heap.HeapSize() >= 2){
                max_heap.InsertKey(min_heap.ExtractTop());
            }

            if(max_heap.HeapSize() == min_heap.HeapSize()){
                mid = (max_heap.GetTop() + min_heap.GetTop())/2.0f;
            }else if(max_heap.HeapSize() > min_heap.HeapSize()){
                mid = max_heap.GetTop();
            }else{
                mid = min_heap.GetTop();
            }

        }
        if(mid - (int)mid > 0.0f){
            cout << fixed << setprecision(2) << mid << '\n' ;
        }else{
            cout << int(mid) << '\n' ;
        }
    }
    return 0;
}


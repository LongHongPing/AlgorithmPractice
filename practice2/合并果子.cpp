#include<iostream>
#include<vector>

#define maxSize 20000

using namespace std;

class littleHeap{		//创建小顶堆
	public:
		vector<int> heap;

		void insert(int value){
			heap.push_back(value);
			int index = heap.size()-1;
			int father = (index-1)/2;
			while(index > 0){
				if(heap[index] < heap[father]){
					swap(heap[index],heap[father]);
					index = father;
					father = (index-1)/2;
				}
				else{
					break;
				}
			}
		}

		void swap(int &value1,int &value2){
			int temp = value1;
			value1 = value2;
			value2 = temp;
		}

		void pop(){
			heap[0] = heap.back();
			heap.pop_back();      //弹出堆顶
			int index = 0;
			int max_index = heap.size()-1;
			int lchild,rchild;
			//重新排堆
			while(index < max_index){
				lchild = index*2+1;
				rchild = index*2+2;
				if(lchild > max_index){
					break;
				}
				else if(rchild > max_index){ 		//找最后那个结点
					if(heap[index] > heap[lchild]){
						swap(heap[index],heap[lchild]);
						index = lchild;
					}
					else{
						break;
					}
				}
				else{		//非根节点时
					int smaller = heap[lchild] <= heap[rchild]?lchild:rchild;
					if(heap[index] > heap[smaller]){
						swap(heap[index],heap[smaller]);
						index = smaller;
					}
					else{
						break;
					}
				}
			}
		}

		int getTop(){
			return heap[0];
		}

		int getSize(){
			return heap.size();
		}
};

int main(){
	int n,i;
	int a[maxSize];
	littleHeap heap;
	
	cin>>n;
	for(i = 0;i < n;i++){
		cin>>a[i];
	}

	for(i = 0;i < n;i++){
		heap.insert(a[i]);
	}

	int sum = 0;
	while(1){
		int h1 = heap.getTop(); heap.pop();
		int h2 = heap.getTop(); heap.pop();
		int h = h1+h2;
		sum += h; 		//消耗总体力
		heap.insert(h);
		if(heap.getSize() == 1){
			break;
		}
	}

	cout<<sum<<endl;

	system("pause");
	return 0;
}
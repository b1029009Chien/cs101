#include <iostream>
#include <cstdlib>
using namespace std;

class MMmanger {
	private:
		int space;
		int* g_mm;
		int** calloced_p;
	public:
		
		MMmanger(int size) {
			space = size;
			calloced_p = new int* [10];//C++用法;
			g_mm = new int [10];//C++用法 
			//calloced_p = (int**)malloc(space * sizeof(int*));
			for(int i = 0; i < space; i++) {
				calloced_p[i] = 0;
			}
			//g_mm = (int*) malloc (space * sizeof(int));
			
		}
		
		int get_MMCapacity() {
			int non_space = 0;
			for(int i = 0; i < space; i++) {
				if(!calloced_p[i]) {
					non_space++;
				}
			}
			return non_space;
		}
		
		int* calloc_MM(int size) {
			int av_size = 0;
			int index;
			for (index = 0; index < space; index++) {
        	//check array[index] i sfree or not
        		(!calloced_p[index]) ?(av_size++): (av_size = 0);
		        //find
		        if (av_size == size) {
		            index -= size-1;
		            break;
		        }
		    }
		    // can not find the space
		    if(av_size < size) {
		        printf_calloc_array(0,size);
		        return NULL;
		    }
		    //alloced these spaces
		    for(int i = 0; i < size; i++) {
		        calloced_p[index+i] = &g_mm[index];
		    }
		    //print out the mms
		    printf_calloc_array(1,0);
		    //return the address of array[index]
		    return &g_mm[index];
		} 
		
		void free_MM(int* p) {
		    for(int i = 0; i < space; i++) {
		        if(calloced_p[i] == p) {
		            calloced_p[i] = NULL;
		        }
		    }
		    printf_calloc_array(1,0);
		}
		
		~MMmanger() {
			delete []g_mm;//C++用法
			delete []calloced_p;//C++用法
			//free(g_mm);
			//free(calloced_p);
		}
				
		void printf_calloc_array(int flag, int size) {
			cout << "Capacity:" << get_MMCapacity() << " - ";
		    for(int i = 0;i < space; i++) {
		        (calloced_p[i])?(cout << "1"):(cout << "0");
		    }
		    if(!flag) {
		        cout << "<-out of space : demand " << size;
		    }
		    if(get_MMCapacity() == 0) cout << " <- No space";
            cout << endl;
		}
};

int main() {
	MMmanger mmer(10);
    int* p1 = mmer.calloc_MM(1);
    int* p2 = mmer.calloc_MM(2);
    int* p3 = mmer.calloc_MM(3);
    int* p4 = mmer.calloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p4);
    int* p5 = mmer.calloc_MM(6);
    return 0;
}

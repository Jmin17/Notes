

#include <vector>


#ifndef SORTER_CLASS
#define SORTER_CLASS
using namespace std;

template< typename T >
class Sorter{
	
public:
	
	static void qSort(vector<T> &v ) {
		qSort(v, 0, v.size()-1);	
	}
	
private:	
	
	static void qSort(vector<T> &v, int left, int right ) {
		
		if (left >= right)
			return;
		
		int index = 0;
		T pivot = v[(left+right)/2];
		
		index = partition( v, left, right, pivot );
		qSort(v,left, index-1);
		qSort(v,index,right);
		
	}
	
	static int partition(vector<T> &v, int left, int right, const T &pivot) {
		
		while ( left <= right )
		{
			while (v[left] < pivot)
			{ left++; }
			
			while (v[right] > pivot)
			{ right--; }
			
			if ( left <= right )
			{	
				swap(v,left,right);
				left++;
				right--;
			}				
			
		}//endwhile
		
		return left;
	}//endfunc
	
	static void swap(vector<T> &v, const int &left, const int &right ) {
		T temp = v[left];
		v[left] = v[right];
		v[right] = temp;
	}
	
};//endclass


#endif

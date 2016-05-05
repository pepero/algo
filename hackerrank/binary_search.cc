int binary_search(int array[],int key){
 int begin = 0;
 int end = array.size()-1;
 while(begin < end){
  int mid = begin + (end-begin)/2;
  if(array[mid] <= key)
   begin = mid+1;
  else if(array[mid] > key)
   end = mid;
 }
 return begin;

 int main() {
 	int a[] = {0, 3, 3, 3, 4, 5}; 
 	int result = binary_search(a, 3);
 	cout << result << endl;
 }
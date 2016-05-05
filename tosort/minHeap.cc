MinHeap(int cap) {
	capacity = cap;
	heapsize = 0;
	int* harray = new int[cap];	
}

int MinHeap::parent(int i) {
	return (i-1)/2;
}

int MinHeap::left(int i) {
	return i*2 + 1;
}

int MinHeap::right(int i) {
	return i*2 + 2;
}

void MinHeap::swap(int i, int j) {
	int t = harray[i];
	harray[i] = harray[j];
	harray[j] = t;
}

void MinHeap::insert(int k){
	if (heapsize == capcity) {
		return;
	}
	harray[heapsize-1] = k;
	i = heapsize-1;
	while(i > 0 && harray[i] < harray[parent(i)]) {
		swap(i, parent(i));
		i = parent(i);
	}
}

void MinHeap::increase(int i, int newval){
	harray[i] = newval;
	while(2*i + 2< capacity && harray[i] > harray[right(i)]) {
		swap(i, right(i));
		i = right(i);
	}
}

// top-down recursive:
void MinHeap::heapify(int i){
	int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(i, smallest);
        MinHeapify(smallest);
    }
}

// top-down iterative:
void MinHeap::heapify_iterative(int i) {
	int j = 0;
	while (2*i+2 < capacity) {
		j = 2*i+1;
		if (!less (left(i), right(i))) j++;
		if (less (harray[i], harray[j])) break;
		swap (i, j); 
		i = j;
	}
}

int MinHeap::extract(){
	if (heapsize == 0) return INT_MAX;
	if (heapsize == 1) {
		heapsize--;
		return harray[0];
	}
	int t = harray[0];
	heapsize--;
	heapify(0);
	return t;
}
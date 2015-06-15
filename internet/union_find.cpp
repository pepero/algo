

int quickUnion(int i, int j){
  while(idx[i]!=i){
    i = idx[i];
  }
    while(idx[j]!=j){
    j = idx[j];
  }
  idx[j] = i;
}

int quickUnion0(int i, int j){
  for(;i!=idx[i]; i=idx[i]));
  for(;j!=idx[j]; j=idx[j]));
  idx[j]=i;
}

int weightQuickUnion(int i, int j, int idx[], int sz[]){
  for(;i!=idx[i]; i=idx[i]));
  for(;j!=idx[j]; j=idx[j]));
  idx[j]=i;
  if (i == j) return;
  else{
    if (sz[i]<sz[j]) {
      idx[i] = j;
      sz[j] +=sz[i];
    } else{
      idx[j] = i;
      sz[i] +=sz[j];
    }
  }
}

int weightQUPC(int i, int j, int idx[], int sz[]){

  // path compress while find root
  for(;i!=idx[i]; i=idx[i])){
    idx[i] = idx[idx[i]];
  }
  // path compress while find root
  for(;j!=idx[j]; j=idx[j])){
    idx[j] = idx[idx[j]];
  }
  idx[j]=i;
  if (i == j) return;
  else{
    if (sz[i]<sz[j]) {
      idx[i] = j;
      sz[j] +=sz[i];
    } else{
      idx[j] = i;
      sz[i] +=sz[j];
    }
  }
}

void initlize(int N, int sz[], int idx[]){
  for (int i=0; i<N; i++){
    idx[i]=i;
    sz[i]=1;
  }
}

main(){
  fstream();


}









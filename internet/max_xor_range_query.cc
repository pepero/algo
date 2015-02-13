/*
 *
 *
 *
 *
 */

class TrieNode{
  vector<int> indexes;
  TrieNode* next[2];
}

int size = sizeof(int) * 8;

void insertNbr(TrieNode* root, int nbr, int index)
{
  int digit = 0; TrieNode* cur = root;
  for (int i = size-1; i>=0; --i){
    digit = nbr & (1 << i);
    cur->indexes.push_back(index);
    if (!cur->next[digit]) {
      cur->next[digit]=new TrieNode();
    cur = cur->next[digit];   
  }
}

bool inRange(int start, int end, vector<int>& vi){
  for (int i=0; i<vi.size(); ++i){
    if (vi[i]>= start && vi[i]<=end)
      return true;
  }
  return false;
}

int maxXORRange(int target, int start, int end, TrieNode* root)
{
  TrieNode* cur = root;
  if (!inrange(start, stop, cur->indexes)){
	return -1;}
  for(int i= size-1, i>=0; --i){
    digit = target & (1 << i);
    if (cur->next[digit] && 
	inrange(start, end, cur->next[digit]->indexes) {
      cur = cur->next[digit];
    } else if (cur->next[1-digit] && 
	inrange(start, end, cur->next[1-digit]->indexes)){
      cur = cur->next[1-digit];
    }
  }
  cur->indexes
}
  
int main(){

}



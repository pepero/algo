/*
 * word_search.cc
 *
 *  Created on: Jun 14, 2015
 *      Author: shao
 */
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
    	m_exist = false;
    	m_rsize = 0;
    	m_csize = 0;
    	m_rsize = board.size();
    	if (m_rsize) m_csize = board[0].size();
    	if (word.length() > m_rsize*m_csize) return false;
    	m_used = vector<vector<bool> >(m_rsize, vector<bool>(m_csize, false));
    	for (int r = 0; r < m_rsize; ++r){
    		for(int c = 0; c < m_csize; ++c){
				dfs(board, word, 0, r, c);
    		}
    	}
    	return m_exist;
    }
    void dfs(vector<vector<char> >& board, string& word, int cnt, int r, int c) {
    	if(word.length() == cnt){
    		m_exist = true;
    		return;
    	} else{
    		if (word[cnt] == board[r][c]){
    			m_used[r][c] = true;
    			if (word.length() == cnt+1){
					m_exist = true;
					return;
				}
    			if (r-1>=0 && !m_used[r-1][c]) {
    				dfs(board, word, cnt+1, r-1, c);
    			}
    			// 2d dimension, how to get the size of each?
    			if (r+1< m_rsize && !m_used[r+1][c]) {
    				dfs(board, word, cnt+1, r+1, c);
    			}
				if (c-1>=0 && !m_used[r][c-1]) {
					dfs(board, word, cnt+1, r, c-1);
				}
				if (c+1<m_csize && !m_used[r][c+1]) {
					dfs(board, word, cnt+1, r, c+1);
				}
    		}
    	}
    }
    vector<vector<bool> > m_used;
    int m_rsize;
    int m_csize;
    bool m_exist;
};

int main(){
	Solution s;
	// how to initialize vector from array??
//	char c1[] = {'c', 'o', 'd', 'e'};
//	char c2[] = {'i', 'n', 't', 'e'};
//	char c3[] =  {'r', 'v', 'i', 'e'};
//	char c4[] =  {'w', '', '', ''};
//	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

	// how to initialize a 2d vector from string "interview" ??
	vector<char> a(1, 'a');
	vector<vector<char> > vv(1, a);
//	string str = "codeinterview";
//	vector<vector<char> > vv(4, vector<char>(4,0));
//	int size = str.length();
//	for(int i=0; i < 4; ++i){
//		for(int j= 0; j < 4; ++j){
//			if(4*i+j < size){
//				vv[i][j]= str[4*i+j];
//			}
//		}
//	}
	if (s.exist(vv, "a")){
		cout << "found";
	}
}

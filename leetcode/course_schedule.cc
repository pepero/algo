/*
 * course_schedule.cc
 *
 *  Created on: Jul 5, 2015
 *      Author: shao
 */
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        m_visited = vector<bool> (numCourses, false);
        for(vector<pair<int, int>>::const_iterator it = prerequisites.begin();
        it != prerequisites.end(); ++it)
        {
            if (!m_visited[it->first]) {
                if (dfsFindLoop(it->first, prerequisites))
                return false;
                m_noLoop = m_visited;
            }
        }
        return true;
    }
    bool dfsFindLoop(int current, vector<pair<int, int>>& prerequisites){
        if (m_noLoop[current]) return false;
        if (m_visited[current]) return true;
        m_visited[current] = true;
        for(int i = 0; i < prerequisites.size(); ++i){
            if (prerequisites[i].first == current){
                if (dfsFindLoop(prerequisites[i].second, prerequisites)) {
                    return true;
                }
            }
        }
        return false;
    }
    vector<bool> m_visited;
    vector<bool> m_noLoop;
};

int main(){

}



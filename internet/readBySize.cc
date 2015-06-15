#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class Input {
public:
    int readIn(int size, char* buffer) {
        static char buf4[4] = {};
        static int pos = 0;
        int nRet = 0;

        if (pos!=0) {
            int nRead = min (size, 4-pos);
            memcpy (buffer, buf4 + pos, nRead);
            nRet = nRead;
            size -= nRet;
            pos = (pos+nRead)%4;
        }
        int nRest = size%4;
        for (int i=0; i<size/4; ++i) {
            int nRead = read4(buf4);
            if (nRead!=0) {
                memcpy(buffer+nRet, buf4, nRead);
                nRet += nRead;
            } else return nRet;
        }
        if (nRest != 0) {
            int nRead = read4(buf4);
            if (nRead!=0) {
                int nCopy = min(nRead, nRest);
                memcpy(buffer+nRet, buf4, nCopy);
                pos = nCopy;
                return nRet + nCopy;
            } 
        }
    }

    Input(const char* chars, int size){
        m_buf = new char[size];
        m_size = size;
        m_eof = false;
        m_posR = 0;
        memcpy (m_buf, chars, size);
    }

private:
    int read4(char* buffer){
        if (!m_eof) {
            if (m_posR + 4 <= m_size ) {
                memcpy(buffer, m_buf + m_posR, 4);
                if (m_posR+4 == m_size) {
                    m_eof = true;
                }
                m_posR +=4;                
                return 4;
            } else {
                memcpy(buffer, m_buf + m_posR, m_size - m_posR);
                m_eof = true;
                m_posR = m_size;
                return m_size-m_posR;
            }
        } else return 0;   
    }

    int m_size;
    char* m_buf;
    int m_posR;
    bool m_eof;
};


int main(){
    char input[20] = "abcdefghijklmnopqrs";
    char output[20] = {};
    Input i(input, 20);
    i.readIn(4,output);
    i.readIn(4,output);
    for(int i=0; i< 10; i++) {
        cout << output[i] <<endl;
    }
}





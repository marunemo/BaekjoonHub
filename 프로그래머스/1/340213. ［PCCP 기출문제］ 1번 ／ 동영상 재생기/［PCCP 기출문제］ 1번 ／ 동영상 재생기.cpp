#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int hh = (pos[0] - '0') * 10 + (pos[1] - '0');
    int mm = (pos[3] - '0') * 10 + (pos[4] - '0');
    
    int op_start_hh = (op_start[0] - '0') * 10 + (op_start[1] - '0');
    int op_start_mm = (op_start[3] - '0') * 10 + (op_start[4] - '0');
    
    int op_end_hh = (op_end[0] - '0') * 10 + (op_end[1] - '0');
    int op_end_mm = (op_end[3] - '0') * 10 + (op_end[4] - '0');
    
    int video_len_hh = (video_len[0] - '0') * 10 + (video_len[1] - '0');
    int video_len_mm = (video_len[3] - '0') * 10 + (video_len[4] - '0');
    
    if(op_start_hh == op_end_hh) {
        if(op_start_hh == hh && op_start_mm <= mm && mm <= op_end_mm)
            hh = op_end_hh, mm = op_end_mm;
    }
    else if(op_start_hh < hh && hh < op_end_hh)
        hh = op_end_hh, mm = op_end_mm;
    else if(op_start_hh == hh && op_start_mm <= mm)
        hh = op_end_hh, mm = op_end_mm;
    else if(op_end_hh == hh && op_end_mm >= mm)
        hh = op_end_hh, mm = op_end_mm;
    
    for(string cmd: commands) {
        if(cmd == "next")
            mm += 10;
        else if(cmd == "prev")
            mm -= 10;
    
        if(mm >= 60) {
            hh++;
            mm -= 60;
        }
        else if(mm < 0) {
            hh--;
            mm += 60;
        }
        
        if(hh < 0) {
            hh = 0, mm = 0;
        }
        
        if(hh > video_len_hh) {
            hh = video_len_hh, mm = video_len_mm;
        }
        else if(hh == video_len_hh && mm >= video_len_mm) {
            hh = video_len_hh, mm = video_len_mm;
        }
        
        if(op_start_hh == op_end_hh) {
            if(op_start_hh == hh && op_start_mm <= mm && mm <= op_end_mm)
                hh = op_end_hh, mm = op_end_mm;
        }
        else if(op_start_hh < hh && hh < op_end_hh)
            hh = op_end_hh, mm = op_end_mm;
        else if(op_start_hh == hh && op_start_mm <= mm)
            hh = op_end_hh, mm = op_end_mm;
        else if(op_end_hh == hh && op_end_mm >= mm)
            hh = op_end_hh, mm = op_end_mm;
    }
    
    if(hh < 10)
        answer += "0";
    answer += to_string(hh);
    answer += ":";
    if(mm < 10)
        answer += "0";
    answer += to_string(mm);
    
    return answer;
}
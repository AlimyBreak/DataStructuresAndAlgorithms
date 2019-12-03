
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>
#include <string>

using namespace std;

struct Student{
    string name;
    int score;
    
    // 重载 <
    bool operator<( const Student& otherStudent){
        //return score < otherStudent.score;  // 分数小于 ----> 学生小于
        
        // 相等的话则判断字符串的字典序
        return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
        
    }
    
    // 重载 <<
    friend ostream& operator<<(ostream& os, const Student& student){
        os << "Student:" << student.name << " " << student.score << endl;
        return os;
    }
};


#endif // !__STUDENT_H__
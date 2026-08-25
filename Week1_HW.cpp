#include <iostream>
#include <string>

struct Teacher{
    std::string name;
    int age;
};
struct Student{
    std::string name;
    int age;
    double score;
};
struct Course{
    Teacher *teacher;
    Student *students[25];
    int count;
};
void addStudent(Course *course,Student *student){
    if(course->count<25){
        course->students[course->count] = student;
        course->count++;
    }else{
        std::cout << "Cannot add more students" << std::endl;
    }
}
void displayCourse(Course *course){
    std::cout << "========================================"<<std::endl;
    std::cout << "COURSE INFORMATION" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Teacher" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Name: "<<course->teacher->name<< std::endl;
    std::cout << "Age: " << course->teacher->age << "\n\n";
    std::cout << "Students: " << course->count << "/25" << std::endl;
    std::cout << "--------------------" << std::endl;
    for (int i = 0; i < course->count;i++){
        std::cout << (i+1) <<". "<< course->students[i]->name << std::endl;
        std::cout << "Age:" << course->students[i]->age << std::endl;
        std::cout << "Score:" << course->students[i]->score << "\n\n";
    }
}

int main()
{
    Teacher teacherA = {"Mr.Sok", 35};
    Course course;
    course.teacher = &teacherA;
    course.count = 0;

    Student s1 = {"Dara", 20, 85.5};
    Student s2 = {"Liza", 21, 91.0};
    Student s3 = {"Sophea", 20, 78.5};

    addStudent(&course, &s1);
    addStudent(&course, &s2);
    addStudent(&course, &s3);

    displayCourse(&course);
    std::cout << "========================================" << std::endl;

    return 0;
}
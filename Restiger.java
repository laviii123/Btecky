import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Course {
    private String code;
    private String title;
    private String description;
    private int capacity;
    private int enrolledStudents;
    private String schedule;

    public Course(String code, String title, String description, int capacity, String schedule) {
        this.code = code;
        this.title = title;
        this.description = description;
        this.capacity = capacity;
        this.enrolledStudents = 0;
        this.schedule = schedule;
    }

    public String getCode() {
        return code;
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    public int getCapacity() {
        return capacity;
    }

    public int getEnrolledStudents() {
        return enrolledStudents;
    }

    public String getSchedule() {
        return schedule;
    }

    public boolean enrollStudent() {
        if (enrolledStudents < capacity) {
            enrolledStudents++;
            return true;
        } else {
            System.out.println("Course is full. Cannot enroll more students.");
            return false;
        }
    }

    public void removeStudent() {
        if (enrolledStudents > 0) {
            enrolledStudents--;
        } else {
            System.out.println("No students enrolled to remove.");
        }
    }

    @Override
    public String toString() {
        return "Course: " + code + " - " + title + "\nDescription: " + description +
               "\nCapacity: " + capacity + "\nEnrolled Students: " + enrolledStudents +
               "\nSchedule: " + schedule;
    }
}

class Student {
    private String studentID;
    private String name;
    private List<Course> registeredCourses;

    public Student(String studentID, String name) {
        this.studentID = studentID;
        this.name = name;
        this.registeredCourses = new ArrayList<>();
    }

    public String getStudentID() {
        return studentID;
    }

    public String getName() {
        return name;
    }

    public List<Course> getRegisteredCourses() {
        return registeredCourses;
    }

    public void registerForCourse(Course course) {
        if (registeredCourses.contains(course)) {
            System.out.println("You are already registered for this course.");
        } else {
            if (course.enrollStudent()) {
                registeredCourses.add(course);
                System.out.println("Registration successful.");
            } else {
                System.out.println("Registration failed. Course is full.");
            }
        }
    }

    public void dropCourse(Course course) {
        if (registeredCourses.contains(course)) {
            registeredCourses.remove(course);
            course.removeStudent();
            System.out.println("Course dropped successfully.");
        } else {
            System.out.println("You are not registered for this course.");
        }
    }

    public void displayRegisteredCourses() {
        System.out.println("Registered Courses for " + name + " (ID: " + studentID + "):");
        for (Course course : registeredCourses) {
            System.out.println(course.getTitle() + " - " + course.getCode());
        }
    }
}

class RegistrationSystem {
    private List<Course> courseDatabase;
    private List<Student> studentDatabase;

    public RegistrationSystem() {
        this.courseDatabase = new ArrayList<>();
        this.studentDatabase = new ArrayList<>();
    }

    public void addCourse(Course course) {
        courseDatabase.add(course);
    }

    public void addStudent(Student student) {
        studentDatabase.add(student);
    }

    public void displayCourseListing() {
        System.out.println("Available Courses:");
        for (Course course : courseDatabase) {
            System.out.println(course.toString() + "\n");
        }
    }

    public Course findCourseByCode(String code) {
        for (Course course : courseDatabase) {
            if (course.getCode().equals(code)) {
                return course;
            }
        }
        return null;
    }

    public Student findStudentByID(String studentID) {
        for (Student student : studentDatabase) {
            if (student.getStudentID().equals(studentID)) {
                return student;
            }
        }
        return null;
    }
}

public class CourseRegistrationSystem {
    public static void main(String[] args) {
        // Create a Registration System
        RegistrationSystem registrationSystem = new RegistrationSystem();

        // Create some courses
        Course c1 = new Course("CSE101", "Introduction to Computer Science", "Fundamentals of programming", 30, "Mon/Wed 10:00 AM");
        Course c2 = new Course("MAT201", "Calculus I", "Limits, derivatives, and integrals", 25, "Tue/Thu 2:00 PM");
        Course c3 = new Course("ENG102", "Composition and Rhetoric", "Effective communication skills", 20, "Mon/Wed/Fri 1:00 PM");

        // Create some students
        Student s1 = new Student("001", "John Doe");
        Student s2 = new Student("002", "Jane Smith");

        // Add courses and students to the registration system
        registrationSystem.addCourse(c1);
        registrationSystem.addCourse(c2);
        registrationSystem.addCourse(c3);

        registrationSystem.addStudent(s1);
        registrationSystem.addStudent(s2);

        // Display available courses
        registrationSystem.displayCourseListing();

        // Example: Student registration for a course
        System.out.println("\nStudent Registration Example:");
        System.out.println("----------------------------");
        System.out.println("Available Courses:");
        registrationSystem.displayCourseListing();

        Scanner scanner = new Scanner(System.in);

        System.out.print("\nEnter student ID for registration: ");
        String studentID = scanner.nextLine();

        Student student = registrationSystem.findStudentByID(studentID);

        if (student != null) {
            System.out.print("Enter course code for registration: ");
            String courseCode = scanner.nextLine();

            Course course = registrationSystem.findCourseByCode(courseCode);

            if (course != null) {
                student.registerForCourse(course);
            } else {
                System.out.println("Course not found.");
            }
        } else {
            System.out.println("Student not found.");
        }

        // Display registered courses for the student
        student.displayRegisteredCourses();

        // Example: Student dropping a course
        System.out.println("\nStudent Course Drop Example:");
        System.out.println("---------------------------");
        System.out.print("Enter course code to drop: ");
        String courseCodeToDrop = scanner.nextLine();

        Course courseToDrop = registrationSystem.findCourseByCode(courseCodeToDrop);

        if (courseToDrop != null) {
            student.dropCourse(courseToDrop);
        } else {
            System.out.println("Course not found.");
        }

        // Display updated registered courses for the student
        student.displayRegisteredCourses();

        scanner.close();
    }

    
}

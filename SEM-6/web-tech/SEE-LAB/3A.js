function studentData() {
  const students = [];

  return {
    addStudent(usn, subjectCode, subjectName, cieMarks, seeMarks) {
      const _cieMarks = cieMarks;
      const _seeMarks = seeMarks;

      const student = {
        usn,subjectCode,subjectName,
        
        getTotalMarks() { return _cieMarks + _seeMarks; },
        
        displayDetails() {
          console.log(`USN: ${this.usn} Subject Code: ${this.subjectCode} Subject Name: ${this.subjectName} Total Marks: ${this.getTotalMarks()} `);
        }
      };
      
      students.push(student);
      return student;
    },
    
    displayAllStudents() {
      console.log("STUDENT DETAILS:");
      students.forEach(student => student.displayDetails());
    },
    
    getStudent(index) {
      return students[index];
    }
  };
}

const manager = studentData();
manager.addStudent("1MS21CS001", "21CS42", "Operating Systems", 40, 45);
manager.addStudent("1MS21CS002", "21CS43", "Algorithms", 38, 49);
manager.displayAllStudents();
const firstStudent = manager.getStudent(0);
console.log("Attempting to access private CIE marks:", firstStudent._cieMarks); // undefined, as expected
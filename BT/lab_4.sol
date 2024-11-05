// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleStudentManagement {
    struct Student {
        string name;
        uint256 age;
        string major;
        uint256[] grades;
    }
    
    address public owner;
    mapping(uint256 => Student) public students;
    uint256 public studentCount;
    
    event StudentAdded(uint256 indexed id, string name);
    event GradeAdded(uint256 indexed id, uint256 grade);
    event FallbackCalled(address sender, uint256 value);
    
    constructor() {
        owner = msg.sender;
    }
    
    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this");
        _;
    }
    
    function addStudent(
        string memory _name,
        uint256 _age,
        string memory _major
    ) public onlyOwner returns (uint256) {
        uint256 newId = studentCount;
        students[newId] = Student(_name, _age, _major, new uint256[](0));
        
        emit StudentAdded(newId, _name);
        studentCount++;
        return newId;
    }
    
    function addGrade(uint256 _studentId, uint256 _grade) public onlyOwner {
        require(_studentId < studentCount, "Student does not exist");
        require(_grade <= 100, "Grade must be between 0 and 100");
        
        students[_studentId].grades.push(_grade);
        emit GradeAdded(_studentId, _grade);
    }
    
    function getStudent(uint256 _studentId) public view returns (
        string memory name,
        uint256 age,
        string memory major,
        uint256[] memory grades
    ) {
        require(_studentId < studentCount, "Student does not exist");
        Student storage student = students[_studentId];
        return (student.name, student.age, student.major, student.grades);
    }
    
    function getAverageGrade(uint256 _studentId) public view returns (uint256) {
        require(_studentId < studentCount, "Student does not exist");
        
        uint256[] storage grades = students[_studentId].grades;
        if (grades.length == 0) return 0;
        
        uint256 sum = 0;
        for (uint256 i = 0; i < grades.length; i++) {
            sum += grades[i];
        }
        return sum / grades.length;
    }

    fallback() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }

    receive() external payable {
        emit FallbackCalled(msg.sender, msg.value);
    }
}
// SPDX-License-Identifier: MIT
pragma solidity >=0.7.0 <0.9.0;

contract StudentRegistry{
    
    struct Student{
        uint256 rollno;
        string name;
        uint256 age;
    }

    Student[] private students;
    mapping(uint256=>uint256) private rollToIndex;
    
    event ReceivedEther(address sender, uint256 value);

    receive() external payable {
       
        emit ReceivedEther(msg.sender, msg.value);
    }

    fallback() external payable {
    
        emit ReceivedEther(msg.sender, msg.value);
    }

    // event StudentAdded(uint256 roll, string name, uint256 age);

    function addStudent(uint256 roll, string memory name, uint256 age) public {
        require(rollToIndex[roll]==0, "Student with given roll number already exists!");

        students.push(Student(roll,name,age));
        rollToIndex[roll]=students.length;

        // emit StudentAdded(roll, name, age);
    }

    // fallback() external { 
    //     emit StudentAdded(0, "", 12);
    // }

    function getStudent(uint256 roll) public view returns( uint256, string memory, uint256){

        require( rollToIndex[roll]!=0, "Roll number does not exist!");

        uint256 index = rollToIndex[roll]-1;
        Student memory student = students[index];

        return (student.rollno, student.name, student.age);

    }

    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }

    
}
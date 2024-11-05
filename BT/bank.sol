// SPDX-License-Identifier: MIT
pragma solidity >=0.7.0 <0.9.0;

contract Bank{

    mapping (address=>uint) private balances;
    mapping (string=>address) public names;



    function createUser(string memory nme) public {
        balances[msg.sender]=0;
        names[nme]=msg.sender;
    }

    function deposit(uint amount) public payable returns (string memory) {
        require(amount>0, "Amount to be deposited should be greater then 0");
        balances[msg.sender]+=amount;

        return "Amount Deposited to account";
    }

    function showError(uint code) private pure returns (string memory){
        if(code==1){
            return "Insufficient balance!";
        }

        return "Internal server error";
    }

    function withdraw(uint amount) public returns (string memory) {
        require(balances[msg.sender]>=amount, showError(1));
        balances[msg.sender]-=amount;

        return "Amount withdrawn";
    }

    function transfer(string memory recipient, uint amount) public returns (string memory){
        require(balances[msg.sender]>=amount, "Insufficient balance!");
        require(names[recipient]!=msg.sender, "Cannot transfer to Self!");
        balances[msg.sender]-=amount;
        balances[names[recipient]]+=amount;

        return "Amount Transferred";
    }

    function getBalance() public view returns (uint){
        return balances[msg.sender];
    }
}
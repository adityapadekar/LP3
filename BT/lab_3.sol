// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {
    address public owner;
    mapping(address => uint) private accounts;

    constructor() {
        owner = msg.sender;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner con perform this action");
        _;
    }

    function deposit() external payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");
        accounts[msg.sender] += msg.value;
    }

    function withdraw(uint _amount) external {
        require(_amount > 0, "Withrawal amount must be greater than 0");
        require(accounts[msg.sender] >= _amount, "Insufficient balance");

        accounts[msg.sender] -= _amount;

        (bool success, ) = msg.sender.call{value: _amount}("");
        require(success, "Transfer failed");
    }

    function getBalance() public view returns (uint) {
        return accounts[msg.sender];
    }

    function getBankVolume() public view onlyOwner returns (uint) {
        return address(this).balance;
    }
}

//{ Driver Code Starts
// Initial Template for javascript

"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => { inputString += inputStdin; });

process.stdin.on("end", (_) => {
    inputString =
        inputString.trim().split("\n").map((string) => { return string.trim(); });

    main();
});

function readLine() { return inputString[currentLine++]; }

class Node {
    constructor(x) {
        this.data = x;
        this.next = null;
    }
}

function printList(head) {
    let s = "";
    while (head) {
        s += head.data + " ";
        head = head.next;
    }
    console.log(s);
}

function main() {
    let t = parseInt(readLine());
    let i = 0;
    for (; i < t; i++) {
        let input_ar1 = readLine().split(" ").map((x) => parseInt(x));
        let head = new Node(input_ar1[0]);
        let tail = head;
        for (let i = 1; i < input_ar1.length; i++) {
            tail.next = new Node(input_ar1[i]);
            tail = tail.next;
        }

        let obj = new Solution();
        head = obj.segregate(head);
        printList(head);
        console.log("~");
    }
}
// } Driver Code Ends


/* class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
} */

/**
 * @param {Node} head
 * @returns {Node}
 */
class Solution {
   segregate(head) {
        let sortArray=[];
        let firstHead=head;
        while(firstHead){
            sortArray.push(firstHead.data);
            firstHead=firstHead.next;
        }
        const sortNUmber=sortArray.sort((a,b)=>a-b);
        let currenthead=head;
        for (let i of sortNUmber){
            currenthead.data=i;
            currenthead=currenthead.next;
        }
        return head;
   }
}
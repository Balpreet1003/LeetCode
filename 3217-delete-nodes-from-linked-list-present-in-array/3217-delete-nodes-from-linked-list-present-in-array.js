/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */

function binary_search(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (arr[mid] === target) return true;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
var modifiedList = function(nums, head) {
    nums.sort(function(a,b){
        return a-b;
    })
    let node=head;
    let prev=null;
    while(node){
        if(binary_search(nums, node.val)){
            if(node==head){
                head=node.next;
                node.next=null;
                node=head;
            }
            else{
                prev.next=node.next;
                node.next=null;
                node=prev.next;
            }
        }
        else{
            prev=node;
            node=node.next;
        }
    }
    return head;
};
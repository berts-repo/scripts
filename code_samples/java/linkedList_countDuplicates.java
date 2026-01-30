/*
 * LinkedListCountDuplicates
 * Compile: javac linkedList_countDuplicates.java
 * Run:     java LinkedListCountDuplicates
 */
class LinkedListCountDuplicates {
    private static class ListNode {
        int data;
        ListNode next;

        ListNode(int data) {
            this.data = data;
        }
    }

    private ListNode front;

    public LinkedListCountDuplicates(int[] sortedValues) {
        for (int i = sortedValues.length - 1; i >= 0; i--) {
            ListNode node = new ListNode(sortedValues[i]);
            node.next = front;
            front = node;
        }
    }

    // Counts duplicates in a sorted list (adjacent equal values).
    public int countDuplicates() {
        int count = 0;
        ListNode current = front;
        while (current != null && current.next != null) {
            if (current.data == current.next.data) {
                count++;
            }
            current = current.next;
        }
        return count;
    }

    public static void main(String[] args) {
        LinkedListCountDuplicates list = new LinkedListCountDuplicates(new int[]{1, 1, 2, 3, 3, 3, 5});
        System.out.println("Duplicate count: " + list.countDuplicates());
    }
}

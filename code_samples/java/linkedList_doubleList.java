/*
 * LinkedListDoubleList
 * Compile: javac linkedList_doubleList.java
 * Run:     java LinkedListDoubleList
 */
class LinkedListDoubleList {
    private static class ListNode {
        int data;
        ListNode next;

        ListNode(int data) {
            this.data = data;
        }
    }

    private ListNode front;

    public LinkedListDoubleList(int[] values) {
        for (int i = values.length - 1; i >= 0; i--) {
            ListNode node = new ListNode(values[i]);
            node.next = front;
            front = node;
        }
    }

    // Doubles the list by appending a copy of the original sequence.
    public void doubleList() {
        if (front == null) {
            return;
        }

        ListNode last = front;
        int size = 1;
        while (last.next != null) {
            last = last.next;
            size++;
        }

        ListNode original = front;
        for (int i = 0; i < size; i++) {
            ListNode newNode = new ListNode(original.data);
            last.next = newNode;
            last = newNode;
            original = original.next;
        }
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        ListNode current = front;
        while (current != null) {
            sb.append(current.data);
            if (current.next != null) {
                sb.append(" -> ");
            }
            current = current.next;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        LinkedListDoubleList list = new LinkedListDoubleList(new int[]{1, 2, 3});
        System.out.println("Before: " + list);
        list.doubleList();
        System.out.println("After:  " + list);
    }
}

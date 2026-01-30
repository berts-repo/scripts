/*
 * LinkedListDeleteBack
 * Compile: javac linkedList_deleteBack.java
 * Run:     java LinkedListDeleteBack
 */
import java.util.NoSuchElementException;

class LinkedListDeleteBack {
    private static class ListNode {
        int data;
        ListNode next;

        ListNode(int data) {
            this.data = data;
        }
    }

    private ListNode front;

    public LinkedListDeleteBack(int[] values) {
        for (int i = values.length - 1; i >= 0; i--) {
            ListNode node = new ListNode(values[i]);
            node.next = front;
            front = node;
        }
    }

    // Deletes the last value and returns it.
    public int deleteBack() {
        if (front == null) {
            throw new NoSuchElementException("Empty list");
        }
        if (front.next == null) {
            int deletedValue = front.data;
            front = null;
            return deletedValue;
        }

        ListNode current = front;
        while (current.next.next != null) {
            current = current.next;
        }
        int deletedValue = current.next.data;
        current.next = null;
        return deletedValue;
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
        LinkedListDeleteBack list = new LinkedListDeleteBack(new int[]{10, 20, 30});
        System.out.println("Before: " + list);
        int removed = list.deleteBack();
        System.out.println("Removed: " + removed);
        System.out.println("After:  " + list);
    }
}

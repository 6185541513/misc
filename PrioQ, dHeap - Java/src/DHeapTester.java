

import static org.junit.Assert.*;

import java.util.PriorityQueue;
import java.util.Random;

import org.junit.Before;
import org.junit.Test;

public class DHeapTester {

	private DHeap<Integer> heap = new DHeap<Integer>(4);

	@Test
	public void testFunctionality() {
		Random rnd = new Random();
		PriorityQueue<Integer> oracle = new PriorityQueue<Integer>();

		assertEquals(oracle.isEmpty(), heap.isEmpty());

		for (int n = 0; n < 1000; n++) {
			int tal = rnd.nextInt(1000);
			heap.insert(tal);
			oracle.add(tal);

			while (!heap.isEmpty() && rnd.nextBoolean()) {
				assertEquals(oracle.poll(), heap.deleteMin());
			}

			assertEquals(oracle.isEmpty(), heap.isEmpty());
		}
	}

	@Test
	public void testConstructors() {
		heap = new DHeap<Integer>(); // Skapar en bin�rheap
		heap = new DHeap<Integer>(2); // Skapar ytterligare en bin�rheap
		heap = new DHeap<Integer>(3); // Skapar en 3-heap, dvs en heap d�r varje
										// nod har 3 barn
	}

	@Test(expected = IllegalArgumentException.class)
	public void testTooSmallD() {
		new DHeap<Integer>(1);
	}

	@Test
	public void testParentIndex() {
		assertEquals(5, heap.parentIndex(18));
		assertEquals(5, heap.parentIndex(21));
		assertEquals(6, heap.parentIndex(22));
		assertEquals(2, heap.parentIndex(6));
		assertEquals(1, heap.parentIndex(2));
		heap = new DHeap<Integer>();
		assertEquals(1, heap.parentIndex(2));
		assertEquals(1, heap.parentIndex(3));
		assertEquals(4, heap.parentIndex(8));
		assertEquals(4, heap.parentIndex(9));
		assertEquals(6, heap.parentIndex(12));
		assertEquals(6, heap.parentIndex(13));
		heap = new DHeap<Integer>(3);
		assertEquals(6, heap.parentIndex(17));
		assertEquals(3, heap.parentIndex(9));
		assertEquals(4, heap.parentIndex(13));
		assertEquals(1, heap.parentIndex(3));
	}


	@Test(expected = IllegalArgumentException.class)
	public void testTooLowParentIndex() {
		heap.parentIndex(1);
	}

	@Test
	public void testFirstChildIndex() {
		assertEquals(2, heap.firstChildIndex(1));
		assertEquals(6, heap.firstChildIndex(2));
		assertEquals(18, heap.firstChildIndex(5));
		assertEquals(22, heap.firstChildIndex(6));
		assertEquals(26, heap.firstChildIndex(7));
		heap = new DHeap<Integer>();
		assertEquals(2, heap.firstChildIndex(1));
		assertEquals(4, heap.firstChildIndex(2));
		assertEquals(6, heap.firstChildIndex(3));
		assertEquals(8, heap.firstChildIndex(4));
		heap = new DHeap<Integer>(3);
		assertEquals(2, heap.firstChildIndex(1));
		assertEquals(5, heap.firstChildIndex(2));
		assertEquals(11, heap.firstChildIndex(4));
		assertEquals(17, heap.firstChildIndex(6));

	}

	@Test(expected = IllegalArgumentException.class)
	public void testTooLowChildIndex() {
		heap.firstChildIndex(0);
	}

	private void testValues(Integer... expected) {
		assertEquals(expected.length, heap.size());
		for (int n = 0; n < expected.length; n++)
			assertEquals(expected[n], heap.get(n + 1));
	}

	@Test
	public void testContent() {
		testValues();
		heap.insert(17);
		testValues(17);
		heap.insert(23);
		testValues(17, 23);
		heap.insert(5);
		testValues(5, 23, 17);
		heap.insert(12);
		testValues(5, 23, 17, 12);
		heap.insert(100);
		heap.insert(51);
		heap.insert(52);
		testValues(5, 23, 17, 12, 100, 51, 52);
		heap.insert(4);
		testValues(4, 5, 17, 12, 100, 51, 52, 23);
		heap.insert(70);
		testValues(4, 5, 17, 12, 100, 51, 52, 23, 70);
		heap.insert(10);
		testValues(4, 5, 10, 12, 100, 51, 52, 23, 70, 17);
		heap.insert(1);
		testValues(1, 5, 4, 12, 100, 51, 52, 23, 70, 17, 10);

		assertEquals(1, (int) heap.deleteMin());
		testValues(4, 5, 10, 12, 100, 51, 52, 23, 70, 17);
		assertEquals(4, (int) heap.deleteMin());
		testValues(5, 17, 10, 12, 100, 51, 52, 23, 70);
		assertEquals(5, (int) heap.deleteMin());
		testValues(10, 17, 70, 12, 100, 51, 52, 23);
	}

}


import java.util.*;

public class MyALDAList<E> implements ALDAList<E>{
	private int modCount = 0;
	private int size;
	private Node<E> head;
	private Node<E> tail;

	public MyALDAList(){
		size = 0;
		tail = new Node<E>(null, null);
		head = new Node<E>(null, tail);
	}

	private static class Node<E>{
		public Node(E d, Node<E> n){
			data = d;
			next = n;
		}

		public E data;
		public Node<E> next;
	}

	public void add(E element){
		Node<E> travelNode = head;
		while(travelNode.next != tail){
			travelNode = travelNode.next;
		}
		Node<E> addedNode = new Node<E>(element, tail);
		travelNode.next = addedNode;
		modCount++;
		size++;
	}

	public void add(int index, E element){
		if(index < 0 || index > size){
			throw new IndexOutOfBoundsException();
		}

		Node<E> travelNode = head;
		for(int i = 0; i < index; i++){
			travelNode = travelNode.next;
		}
		Node<E> addedNode = new Node<E>(element, travelNode.next);
		travelNode.next = addedNode;
		modCount++;
		size++;
	}

	public E remove(int index){
		if(index < 0 || index >= size){
			throw new IndexOutOfBoundsException();
		}

		Node<E> previousNode = head;
		Node<E> travelNode = previousNode.next;
		for(int i = 0; i < index; i++){
			previousNode = previousNode.next;
			travelNode = travelNode.next;
		}
		previousNode.next = travelNode.next;
		modCount++;
		size--;
		return travelNode.data;
	}

	public boolean remove(E element){
		if(contains(element) == false){
			return false;
		}

		Node<E> previousNode = head;
		Node<E> travelNode = previousNode.next;
		while(travelNode.data != element){
			previousNode = previousNode.next;
			travelNode = travelNode.next;
		}
		previousNode.next = travelNode.next;
		modCount++;
		size--;
		return true;
	}

	public E get(int index){
		if(index < 0 || index >= size){
			throw new IndexOutOfBoundsException();
		}

		E element;
		Node<E> travelNode = head.next;
		for(int i = 0; i < index; i++){
			travelNode = travelNode.next;
		}

		element = travelNode.data;
		return element;
	}		

	public boolean contains(E element){
		boolean doContain = false;
		Node<E> travelNode = head.next;
		while(travelNode != tail){
			if(travelNode.data == element){
				doContain = true;
				break;
			}
			travelNode = travelNode.next;
		}
		return doContain;
	}

	public int indexOf(E element){
		if(contains(element) == false){
			return -1;
		}
		int count = 0;
		Node<E> travelNode = head.next;
		while(travelNode.data != element){
			travelNode = travelNode.next;
			++count;
		}
		return count;
	}

	public void clear(){
		head.next = tail;
		size = 0;
		modCount++;
	}

	public int size(){
		return size;
	}

	public String toString(){
		String str = "[";
		Node<E> tattletaleNode = head.next;
		while(tattletaleNode != tail){
			str += tattletaleNode.data;
			if(tattletaleNode.next != tail){
				str += ", ";
			}
			tattletaleNode = tattletaleNode.next;
		}
		str += "]";
		return str;
	}

	public Iterator<E> iterator() {
		return new LinkedListIterator();
	}

	private class LinkedListIterator implements Iterator<E>{
		private Node<E> previousNode = head;
		private Node<E> savedNode = previousNode;
		private Node<E> currentNode = previousNode.next;
		private int expectedModCount = modCount;
		private boolean okToRemove = false;

		public boolean hasNext() {
			return currentNode != tail;
		}

		public E next() {
			if(modCount != expectedModCount){
				throw new ConcurrentModificationException();
			}
			if(!hasNext()){
				throw new NoSuchElementException();
			}
			E nextElement = currentNode.data;
			savedNode = previousNode;
			previousNode = currentNode;
			currentNode = currentNode.next;
			okToRemove = true;
			return nextElement;
		}

		public void remove() {
			if(!okToRemove){
				throw new IllegalStateException();
			}
			if(modCount != expectedModCount){
				throw new ConcurrentModificationException();
			}

			previousNode = savedNode;
			previousNode.next = currentNode;
			size--;
			okToRemove = false;
		}
	}
}






















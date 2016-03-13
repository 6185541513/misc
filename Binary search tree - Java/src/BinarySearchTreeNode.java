
public class BinarySearchTreeNode<T extends Comparable<T>> {

	private T data;
	private BinarySearchTreeNode<T> left;
	private BinarySearchTreeNode<T> right;

	public BinarySearchTreeNode(T data) {
		this.data = data;
	}

	public boolean add(T data) {
		int compareResult = data.compareTo(this.data);
		if(compareResult == 0){
			return false;
		}else if(compareResult < 0){
			if(left == null){
				left = new BinarySearchTreeNode<T>(data);
				return true;
			}else{
				return left.add(data);
			}
		}else if(compareResult > 0){
			if(right == null){
				right = new BinarySearchTreeNode<T>(data);
				return true;
			}else{
				return right.add(data);
			}
		}
		return false;
	}

	public BinarySearchTreeNode<T> remove(T data){    
		int compareResult = data.compareTo(this.data);
		if(compareResult < 0){
			if(left != null){
				left = left.remove(data);
			}
		}else if(compareResult > 0){
			if(right != null){
				right = right.remove(data);
			}
		}else if(left != null && right != null){
			this.data = right.findMin().data;
			right = right.remove(this.data);
		}else{
			if(left != null){
				return left;
			}else{
				return right;
			}
		}
		return this;
	}

	private BinarySearchTreeNode<T> findMin(){
		if(left != null){
			return left.findMin();
		}else{
			return this;
		}
	}

	public boolean contains(T data) {
		int compareResult = data.compareTo(this.data);
		if(compareResult == 0){
			return true;
		}else if(compareResult < 0){
			if(left == null){
				return false;
			}else{
				return left.contains(data);
			}
		}else if(compareResult > 0){
			if(right == null){
				return false;
			}else{
				return right.contains(data);
			}
		}
		return false;
	}

	public int size() {
		int count = 0;
		if(left != null){
			count += left.size();
		}
		if(right != null){
			count += right.size();
		}
		count++;
		return count;
	}



	public int depth() {
		int leftDepth = 0;
		int rightDepth = 0;
		if(left != null){
			leftDepth = depth(left);
		}
		if(right != null){
			rightDepth = depth(right);
		}
		if(leftDepth > rightDepth){
			return leftDepth;
		}else{
			return rightDepth;
		}
	}

	private int depth(BinarySearchTreeNode<T> bstNode){
		if(bstNode == null){
			return 0;
		}
		int leftCount = depth(bstNode.left);
		int rightCount = depth(bstNode.right);
		int count = 0;
		if(leftCount > rightCount){
			count = leftCount+1;
		}else{
			count= rightCount+1;
		}
		return count;
	}

	public String toString() {
		String str = "";
		if(left!= null){
			str+=left.toString() + ", ";
		}
		str+=data;
		if(right != null){
			str+= ", " + right.toString();
		}
		return str;
	}
}

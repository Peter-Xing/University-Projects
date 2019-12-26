
public class Insertion extends Sort{

	@Override
	public int [] sortIntByIndex(int [] arr){
		int [] index = this.getIndex(arr.length);

		for(int i = 1; i < arr.length; i++){
			int key = arr[i];
			int keyIndex = index[i];
			int j = i - 1;
			while( j >= 0 && arr[j] > key){
				if(arr[j] > key){
					arr[j+1] = arr[j];
					index[j+1] = index[j];
					j--;
				}
			}
			arr[j+1] = key;
			index[j+1] = keyIndex;
		}
		return index;
	}

	@Override
	public int [] sortInt(int [] arr){
		int [] index = this.getIndex(arr.length);

		for(int i = 1; i < arr.length; i++){
			int key = arr[i];
			int keyIndex = index[i];
			int j = i - 1;
			while( j >= 0 && arr[j] > key){
				if(arr[j] > key){
					arr[j+1] = arr[j];
					index[j+1] = index[j];
					j--;
				}
			}
			arr[j+1] = key;
			index[j+1] = keyIndex;
		}
		return arr;
	}

	@Override
	public int [] sortStringByIndex(String [] arr){
		int [] index = this.getIndex(arr.length);

		for(int i = 1; i < arr.length; i++){
			String key = arr[i];
			int keyIndex = index[i];
			int j = i - 1;
			//we use compareTo to compare strings in this
			while( j >= 0 && key.compareTo(arr[j])<0){
				if(arr[j].compareTo(key)>0){
					arr[j+1] = arr[j];
					index[j+1] = index[j];
					j--;
				}
			}
			arr[j+1] = key;
			index[j+1] = keyIndex;
		}
		return index;
	}

	@Override
	public String [] sortString(String [] arr){
		int [] index = this.getIndex(arr.length);

		for(int i = 1; i < arr.length; i++){
			String key = arr[i];
			int keyIndex = index[i];
			int j = i - 1;
			//compareTo is used in here
			while( j >= 0 && arr[j].compareTo(key)>0){
				if(arr[j].compareTo(key)>0){
					arr[j+1] = arr[j];
					index[j+1] = index[j];
					j--;
				}
			}
			arr[j+1] = key;
			index[j+1] = keyIndex;
		}
		return arr;
	}


}

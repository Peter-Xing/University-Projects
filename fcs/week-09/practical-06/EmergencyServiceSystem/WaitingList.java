public class WaitingList {
    protected Node head;
    protected int numNodes;

    public WaitingList(){
        this.head = null;
        this.numNodes = 0;
    }

    /**
     * This method will pop the first patient from the waiting list
     * return the patient popped from the waiting list
     */
    public Patient popPatient() {
        if(this.head == null){
            System.out.println("WaitingList is empty");
            return null;
        }
        else if(head.getNext() == null){
            Patient tmp = head.getPatient();
            head.setPatient(null);
            numNodes --;
            return tmp;
        }
        else{
            Patient tmp = head.getPatient();
            head = head.getNext();
            numNodes--;
            return tmp;
        }
    }

    /**
     * This method will add patient into the waiting list according to the triage level
     * @param patient patient's data
     */
    public void addToList(Patient patient) {
        if(head == null){ 
            Node head = new Node(patient);
            numNodes++;
        }
        // more than one patient in the waitinglist
        else{
            Node p = head;
            while (patient.getTriageLevel() <= p.getPatient().getTriageLevel()) {
                p = p.getNext();

                  
            }
        }
    }

    /**
     * print out the information for each patient in waiting list
     */
    public void printList() {
        if(head == null){
            System.out.println("WaitingList is empty");
        }else{
            Node p = head;
            while (p != null) {
                p.printNode();
                p = p.getNext();
            }
        } 
    }

    /**
     * Check whether the patient is in this list or not
     * @return
     */
    public boolean isInList(Patient patient) {
        if (this.head == null) {
            return false;
        }
        Node temp = this.head;
        while(temp != null) {
            if(temp.getPatient().getName().equals(patient.getName())
                    && temp.getPatient().getPhoneNumber().equals(patient.getPhoneNumber())){
                return true;
            }
            temp = temp.getNext();
        }
        return false;
    }
}

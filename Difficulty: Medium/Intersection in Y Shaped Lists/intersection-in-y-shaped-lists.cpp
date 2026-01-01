class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        Node* start1=head1;
        Node* start2=head2;
        while(start1!=start2){
            start1=start1->next;
            start2=start2->next;
            if(start1==NULL) start1=head2;
            if(start2==NULL) start2=head1;
        }
        return start1;
    }
};
package org.fanglz.topcoder.inv2001semia_b;

import java.util.Comparator;
import java.util.Set;
import java.util.TreeSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author summerg
 */


public class MatchMaker {
   public String[] getBestMatches(String[] members, String currentUser, int sf){
       Set<Member> set=new TreeSet<Member>(new MemberComparator());
       Member[] memObjs=new Member[members.length];
       Member currentMember=null;
        for(int i=0;i<members.length;i++){
            memObjs[i]=new Member(members[i],i);
            if(memObjs[i].getName().equals(currentUser))
                currentMember=memObjs[i];
        }
        for(Member member:memObjs){
            if(member==currentMember) continue;
            member.matches(currentMember);
            if(member.getSf()>=sf)
                set.add(member);
        }
        String[] arr=new String[set.size()];
        memObjs=set.toArray(new Member[]{});
        for(int i=0;i<arr.length;i++){
            arr[i]=memObjs[i].getName();
        }
        return arr;
    }

   private class MemberComparator implements Comparator<Member>{

        public int compare(Member mem1, Member mem2) {
            if(mem1.getSf()!=mem2.getSf()) return -(mem1.getSf()-mem2.getSf());
            return mem1.getOriginalOrder()-mem2.getOriginalOrder();
        }

   }

    private class Member{
        private String name;
        private String gender;
        private String requested;
        private String[] answers;
        private int sf;
        private int originalOrder;

        public Member(String information,int originalOrder){
            String[] arr=information.split("\\s+");
            name=arr[0];
            gender=arr[1];
            requested=arr[2];
            answers=new String[arr.length-3];
            for(int i=0;i<answers.length;i++){
                answers[i]=arr[i+3];
            }
            this.originalOrder=originalOrder;
        }

        public void matches(Member member){
            if(member.getRequested().equals(gender)==false){
                this.sf=-1;
                return;
            }
            int counter=0;
            String[] __answers=member.getAnswers();
            if(__answers.length!=answers.length) {
                this.sf=-1;
                return;
            }
            for(int i=0;i<__answers.length;i++){
                if(__answers[i].equals(answers[i])) counter++;
            }
            this.sf=counter;
        }

        public String[] getAnswers() {
            return answers;
        }

        public String getGender() {
            return gender;
        }

        public String getName() {
            return name;
        }

        public String getRequested() {
            return requested;
        }

        public int getSf() {
            return sf;
        }

        public int getOriginalOrder() {
            return originalOrder;
        }

    }
}
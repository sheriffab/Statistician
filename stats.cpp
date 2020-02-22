//stats.cpp
#include "stats.h"
#include<assert.h>

namespace main_savitch_2C
{
//  Postcondition: The object has been initialized, and is ready to accept
//  a sequence of numbers. Various statistics will be calculated about the sequence.
    statistician::statistician( )
    {
        count=0;
        total=0;
        tiniest=0;
        largest=0;
    }

// Postcondition: The number r has been given to the statistician as the next number in
//  its sequence of numbers.
    void statistician::next(double r)
    {
        if(count==0)
        {
            total=r;
            count++;
            tiniest=r;
            largest=r;
        }

        else
        {
            total+=r;
            count+=1;
            if(r<tiniest)   {tiniest=r;}
            if(r>largest)   {largest=r;}
        }

    }



//  Postcondition: The statistician has been cleared, as if no numbers had
//  yet been given to it.
    void statistician::reset( )
    {
        count=0;
        total=0;
        tiniest=0;
        largest=0;
    }

//  Postcondition: The return value is the length of the sequence that has
//  been given to the statistician (i.e., the number of times that the
//  next(r) function has been activated).
    int statistician::length( ) const
    {
        return count;
    }

//  Postcondition: The return value is the sum of all the numbers in the
//  statistician's sequence.
    double statistician::sum( ) const
    {
        return total;
    }
    //  Precondition: length( ) > 0
    //  Postcondition: The return value is the arithmetic mean (i.e., the
    //  average of all the numbers in the statistician's sequence).
    double statistician::mean( ) const
    {
        if(length() > 0)
            return sum()/count;
        return 0.0;

    }

    //  Precondition: length( ) > 0
//  Postcondition: The return value is the tiniest number in the
//  statistician's sequence.
    double statistician::minimum( ) const
    {
        if(length() > 0)
            return tiniest;

    }

    //  Precondition: length( ) > 0
//  Postcondition: The return value is the absolute value of tiniest number in the
//  statistician's sequence.
    double statistician::abs_minimum( ) const
    {
        if(length() > 0){
            if(tiniest < 0) return tiniest*-1;
            else
                return tiniest;
        }

    }
    \
    //  Precondition: length( ) > 0
//  Postcondition: The return value is the absolute value of largest number in the
//  statistician's sequence.
    double statistician::abs_maximum() const
    {
        if(length() > 0 ){
            if(largest < 0) return largest*-1;
            else
                return largest;
        }
    }

    //  Precondition: length( ) > 0
//  Postcondition: The return value is the largest number in the
//  statistician's sequence.
    double statistician::maximum( ) const
    {
        if(length() > 0)
            return largest;
    }

//  Postcondition: The statistician that is returned contains all the
    //  numbers of the sequences of s1 and s2.
    statistician operator + (const statistician& s1, const statistician& s2)
    {
        statistician st;
        st.total=s1.sum()+s2.sum();
        st.count=s1.length()+ s2.length();
        if(s1.maximum() >s2.maximum())
            st.largest=s1.maximum();
        else
            st.largest=s2.maximum();
        if(s1.minimum() >s2.minimum())
            st.tiniest=s2.minimum();
        else
            st.tiniest=s1.minimum();
        return st;
    }

//  Postcondition: The statistician that is returned contains the same
//  numbers that s does, but each number has been multiplied by the scale number.
    statistician operator * (double scale, const statistician& s)
    {
        if(s.length()==0)
            return s;
        else if(scale>=0)
        {
            statistician st;
            st.largest=s.maximum()*scale;
            st.tiniest=s.minimum()*scale;
            st.total=s.sum()*scale;
            st.count=s.length();
            return st;
        }
        else if(scale<0)
        {
            statistician st;

            st.tiniest=s.maximum()*scale;
            if(s.minimum()==0)
                st.largest=0;
            else
                st.largest=s.minimum()*scale;

            st.total=s.total*scale;
            st.count=s.length();
            return st;
        }


    }

//  Postcondition: The return value is true if s1 and s2 have zero
//  length. Also, if the length is greater than zero, then s1 and s2 must
    //  have the same length, the same  mean, the same minimum,
    //  the same maximum, and the same sum.
    bool operator ==(const statistician& s1,const statistician& s2)
    {

        if(s1.maximum()==s2.maximum())
        {
            if(s1.minimum()==s1.minimum())
            {
                if(s1.length()==s2.length())
                {
                    if(s1.sum()==s1.sum())
                        return true;
                }
            }
        }
        return false;
    }
// Precondition: length cannot be zero
// postcondition: return true if s1 and doesnt have the same maximum, minimum, length and sum

    bool operator !=(const statistician& s1,const statistician& s2)
    {
        if(s1.maximum()!=s2.maximum())
        {
            if(s1.minimum()!=s1.minimum())
            {
                if(s1.length()!=s2.length())
                {
                    if(s1.sum()!= s1.sum())
                        return true;
                }
            }
        }
        return false;
    }
}


//stats.h
// name: sheriff sanni
#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>

namespace main_savitch_2C
{
    class statistician
    {
    public:

        statistician( );
        void next(double r);
        void reset( );
        int length( ) const;
        double recent( ) const;
        double sum( ) const;
        double mean( ) const;
        double minimum( ) const;
        double maximum( ) const;
        double abs_minimum( ) const;
        double abs_maximum( ) const;

        friend statistician operator + (const statistician& s1, const statistician& s2);

        friend statistician operator * (double scale, const statistician& s);

    private:
        // How many numbers in the sequence
        int count;

        // The sum of all the numbers in the sequence
        double total;

        // The smallest number in the sequence
        double tiniest;

        // The largest number in the sequence
        double largest;
    };

    // NON-MEMBER functions for the Statistician class


    bool operator ==(const statistician& s1, const statistician& s2);


    bool operator !=(const statistician& s1, const statistician& s2);
}

#endif

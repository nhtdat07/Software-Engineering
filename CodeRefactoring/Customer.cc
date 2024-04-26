// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.hh"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  std::vector< Rental >::iterator iter = _rentals.begin();
  std::vector< Rental >::iterator iter_end = _rentals.end();
  std::ostringstream result;
  result << "Rental Record for " << getName() << "\n";
  for ( ; iter != iter_end; ++iter ) {
    Rental each = *iter;

    // determine amounts for each line
    double thisAmount = iter->getCharge();

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;
  }
  // add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}

std::string Customer::htmlstatement()
{
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  std::vector< Rental >::iterator iter = _rentals.begin();
  std::vector< Rental >::iterator iter_end = _rentals.end();
  std::ostringstream result;
  result << "{\n\t\"Name\": " << getName() << "\n\t\"RentalRecord\": [\n";
  for ( ; iter != iter_end; ++iter ) {
    Rental each = *iter;

    // determine amounts for each line
    double thisAmount = iter->getCharge();

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t\t{\n\t\t\t\"Title\": \"" << each.getMovie().getTitle() << "\",\n\t\t\t\"Amount\": "
           << thisAmount << "\n\t\t}" << (iter == iter_end - 1 ? "\n\t],\n" : ",\n");
    totalAmount += thisAmount;
  }
  // add footer lines
  result << "\t\"AmountOwed\": " << totalAmount << ",\n";
  result << "\t\"FrequentRentalPoint\": " << frequentRenterPoints
         << "\n}";
  return result.str();
}

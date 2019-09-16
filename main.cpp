#include <gtest/gtest.h>

#include "./utClothes.h"
#include "./utClothesCatalog.h"
#include "./utOrder.h"
#include "./utHistory.h"
#include "./utCustomer.h"
#include "./utTShop.h"
#include "./utCustomerTracker.h"

int main( int argc , char **argv )
{
    testing :: InitGoogleTest( &argc , argv ) ;
    return RUN_ALL_TESTS( ) ;
}

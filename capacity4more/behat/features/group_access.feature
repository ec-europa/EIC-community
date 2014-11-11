Feature: Group access
  Test group access

  @api
  Scenario: Check public group
    Given a group "My bad hair day new group 1" with "Public" access and "badhairgroup1" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "My bad hair day new group 1" node of type "group"
     Then I should get a "200" HTTP response
      And I should see "Subscribe to group"

  @api
  Scenario: Check private group
    Given a group "My bad hair day new group 2" with "Private" access and "badhairgroup2" url is created with group manager "turing"
     When I am logged in as user "isaacnewton"
      And I visit "My bad hair day new group 2" node of type "group"
     Then I should get a "403" HTTP response

  @api
  Scenario: Check restricted group accessed by accepted user
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction and "badhairgroup3" url is created with group manager "turing"
      And I am logged in as user "isaacnewton"
     When I visit "My bad hair day new group 3" node of type "group"
     Then I should get a "200" HTTP response
      And I should see "Request group membership"

  @api
  Scenario: Check restricted group accessed by denied used
    Given a moderated group "My bad hair day new group 3" with "gravity.com" restriction and "badhairgroup3" url is created with group manager "turing"
      And I am logged in as user "badhairday"
     When I visit "My bad hair day new group 3" node of type "group"
     Then I should get a "403" HTTP response

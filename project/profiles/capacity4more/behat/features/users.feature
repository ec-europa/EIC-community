Feature: Testing user creation/manipulations.

  @api
  Scenario: Testing the user firstname+lastname URL alias path.
     Given I am an anonymous user
      When I visit "/users/charles-darwin"
      Then I should have access to the page

  @api
  Scenario: Testing the user profile fields
     Given I am an anonymous user
      When I visit "/users/galileo-galilei"
      Then I should see a "Country" field
      Then I should see a "Topics" field
       And I should see a "Topics of Expertise" field
       And I should see a "Regions & Countries" field
       And I should see a "About You" field
       And I should see a "Notable Contributions" field

  @api
  Scenario: The user tries to leave the platform but still has groups.
    Given I am logged in as user "mariecurie"
     When I visit the leave platform page of the current user
     Then I should see "You can't leave the platform"

  @api @c
  Scenario: The user leaves the platform.
    Given I am logged in with a temporal user
     When I visit the leave platform page of the current user
      And I check the box "I no longer want my name to appear on contents I have contributed - please make all my content anonymous"
      And I fill in "edit-feedback" with "Just testing leaving the platform."
      And I press "Confirm"
      And I wait
      And I wait
     Then I should test to see "Your account has been successfully removed from the platform"
#     Then I should see "Cancelling account"

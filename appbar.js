// $Id$
Drupal.behaviors.appbar = function (context) {
  $('#appbar_alerts').click(function() {
    $('#appbar_alerts_list').toggle();
  });
}
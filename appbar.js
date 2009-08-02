// $Id$
Drupal.behaviors.appbar = function (context) {
  $('#appbar_container').show();
  var interval = setInterval("$('#appbar_count').load('/appbar/refresh/count')", Drupal.settings.appbar.delay);
  $('#appbar_alerts').click(function() {
    $('#appbar_alerts_list').toggle();
    $('#appbar_alerts_list').load('/appbar/refresh/list');
    $('#appbar_count').load('/appbar/refresh/count');
  });
}
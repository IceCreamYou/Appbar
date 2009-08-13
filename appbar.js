// $Id$
Drupal.behaviors.appbar = function (context) {
  $('body').addClass('with-appbar');
  $('#appbar_container').show();
  var interval = setInterval("appbar_refresh();", Drupal.settings.appbar.delay);
  $('#appbar_alerts').click(function() {
    $('#appbar_alerts_list').toggle();
    $('#appbar_alerts_list').load('/appbar/refresh/list');
    $('#appbar_count').load('/appbar/refresh/count');
  });
}
function appbar_refresh() {
  $('#appbar_count').load('/appbar/refresh/count');
  $('#appbar_messages').toggleClass('appbar-has-new', parseInt($('#appbar_count').html()) > 0); /* Doesn't work. Always shows class. */
}
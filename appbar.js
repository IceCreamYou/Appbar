// $Id$
Drupal.behaviors.appbar = function (context) {
  $('body').addClass('with-appbar');
  appbar_tn();
  $('#appbar_container').show();
  var interval = setInterval("appbar_refresh();", Drupal.settings.appbar.delay);
  $('#appbar_alerts').click(function() {
    $('#appbar_alerts_list').toggle();
    $('#appbar_alerts_list').load(Drupal.settings.appbar.base_path +'appbar/refresh/list');
    appbar_refresh();
  });
}
function appbar_refresh() {
  $('#appbar_count').load(Drupal.settings.appbar.base_path +'appbar/refresh/count');
  //Delay switching the class until the new count has loaded.
  setTimeout("appbar_tn()", 1000);
}
//JQuery 1.3 has the more efficient toggleClass(class, switch).
function appbar_tn() {
  if (parseInt($('#appbar_count').html()) > 0) {
    $('#appbar_messages').addClass('appbar-has-new');
  }
  else {
    $('#appbar_messages').removeClass('appbar-has-new');
  }
}
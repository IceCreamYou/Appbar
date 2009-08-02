// $Id$
appbar_count = Drupal.settings.appbar.count;
Drupal.behaviors.appbar = function (context) {
  $('#appbar_container').show();
  appbar_refresh();
  var interval = setInterval("appbar_refresh()", Drupal.settings.appbar.delay);
  $('#appbar_alerts').click(function() {
    $('#appbar_alerts_list').toggle();
  });
}
function appbar_refresh() {
  $('#appbar_count').load('/appbar/refresh/count');
  $('#appbar_alerts_list').load('/appbar/refresh/list');
  /*
  $.ajax({
    url: '/appbar/refresh/count',
    cache: false,
    success: function(data, textStatus) {
      if (appbar_count != data) {
        appbar_count = data;
        $('#appbar_count').html(data);
        $('#appbar_alerts_list').load('/appbar/refresh/list');
      }
    },
    error: function(XMLHttpRequest, textStatus, errorThrown) {
      $('#appbar_count').html('error');
    }
  });
  */
}
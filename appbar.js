// $Id$
Drupal.behaviors.appbar = function (context) {
  if (context == document) {
    $('body').addClass('with-appbar');
    var interval = setInterval("appbar_refresh();", Drupal.settings.appbar.delay);
    context = $(document);
  }
  appbar_tn();
  context.find('#appbar_container').show();
  context.find('#appbar_alerts').click(function() {
    $('#appbar_alerts_list').toggle();
    if ($('#appbar_messages').css('background-image') == 'url("'+ Drupal.settings.appbar.open_path +'")') {
      $('#appbar_messages').css('background-image', 'url("'+ Drupal.settings.appbar.close_path +'")');
    }
    else {
      $('#appbar_messages').css('background-image', 'url("'+ Drupal.settings.appbar.open_path +'")');
    }
    $('#appbar_alerts_list').load(Drupal.settings.appbar.base_path +'appbar/refresh/list');
    appbar_refresh();
  });
  context.find('.appbar-block-popup .appbar-block-title').click(function(e) {
    e.preventDefault();
    var content = $(this).prev('.appbar-block-content');
    var visible = content.slideToggle('fast').attr('display');
    if (visible != 'none') {
      $('.appbar-block-content:visible').not(content).hide();
    }
  });
  context.find('.appbar-block-popup .appbar-minimize').click(function(e) {
    e.preventDefault();
    $(this).parent().parent().slideToggle('fast');
  });
  $('.appbar-block-popup').each(function(index) {
    $(this).find('.appbar-block-content').css('left', $(this).css('left'));
  });
  $('.appbar-block:first').addClass('first');
  $('.appbar-block:last').addClass('last');
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
